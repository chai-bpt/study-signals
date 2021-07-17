#include <stdio.h>
#include <unistd.h>
#include <signal.h>

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

	act.sa_handler = signal_handler;

	sigaction(SIGINT, &act, NULL);

	printf("\n\tsignal handler registered\n");

	sleep(10);

	printf("\n");
}


