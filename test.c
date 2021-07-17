#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void signal_handler(int signal)
{
	printf("\n\tsignal handler::signal = %d\n",signal);
	sleep(2);
	printf("\n\tsignal handler::exit\n\t");
	return;
}

int main(int argvc, char* argv[])
{
	struct sigaction act = {0};
	int fd = 0;
	char buf[1024] = "NIL";

	act.sa_handler = signal_handler;
	act.sa_flags = SA_RESTART;
	
	fd = open("./NamedPipeFile", O_RDWR);
	
	sigaction(SIGINT, &act, NULL);

	printf("\n\tsignal handler registered\n");

	read(fd, buf, 1024);

	printf("\n\tbuf = %s\n",buf);

	printf("\n");
}


