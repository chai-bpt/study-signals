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

int main(int argvc, char* argv[])
{
	struct sigaction act_int;
	sigset_t set;

	memset(&act_int, 0, sizeof(act_int));
	act_int.sa_handler = signal_handler_sigint;
	printf("\n\tRegistering SIGINT handler\n");
	sigaction(SIGINT, &act_int, NULL);
	printf("\n\tRegistered SIGINT handler\n");
	sleep(10);

	sigemptyset(&set);
        sigaddset(&set, SIGINT);
	printf("\n\tBlocking SIGINT");
        sigprocmask(SIG_BLOCK, &set, NULL);
        printf("\n\tSIGINT blocked\n");
	sleep(10);

	sigemptyset(&set);
        sigaddset(&set, SIGINT);
	printf("\n\tUnblocking SIGINT");
        sigprocmask(SIG_UNBLOCK, &set, NULL);
        printf("\n\tSIGINT unblocked\n");
        sleep(10);

	printf("\n");
}


