#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void signal_handler_sigint(int signal)
{
	printf("\n\tsignal handler SIGINT::signal = %d\n",signal);
	sleep(1);
	printf("\n\tsignal handler SIGINT::exit\n\t");
	return;
}

void signal_handler_sigquit(int signal)
{
        printf("\n\tsignal handler SIGQUIT::signal = %d\n",signal);
        sleep(1);
        printf("\n\tsignal handler SIGQUIT::exit\n\t");
        return;
}
int main(int argvc, char* argv[])
{
	struct sigaction act_int, act_quit;
	
	act_int.sa_handler = signal_handler_sigint;	
	act_quit.sa_handler = signal_handler_sigquit;
	
	sigaction(SIGINT, &act_int, NULL);
	sigaction(SIGQUIT,&act_quit, NULL);

	printf("\n\tsignal handler registered\n");

	sleep(10);

	printf("\n");
}


