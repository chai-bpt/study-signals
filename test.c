#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

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
	sigset_t set_int, set_quit;

	memset(&act_int, 0, sizeof(act_int));
	memset(&act_quit, 0, sizeof(act_quit));

	sigemptyset(&set_int);
	sigemptyset(&set_quit);

	sigaddset(&set_int, SIGQUIT);

	act_int.sa_handler = signal_handler_sigint;
	act_int.sa_mask = set_int;

	act_quit.sa_handler = signal_handler_sigquit;
	
	sigaction(SIGINT, &act_int, NULL);
	sigaction(SIGQUIT,&act_quit, NULL);

	printf("\n\tsignal handler registered\n");

	sleep(10);

	printf("\n");
}


