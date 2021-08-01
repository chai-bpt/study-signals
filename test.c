#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/signalfd.h>

void signal_handler(int signal)
{
	printf("\n\tsignal handler::signal = %d\n",signal);
	sleep(1);
	printf("\n\tsignal handler::exit\n\t");
	return;
}

int main(int argvc, char* argv[])
{
	struct sigaction act;
	sigset_t set;
	int i = 0;
	siginfo_t info;
	struct signalfd_siginfo fdinfo;
	int sfd = 0;
	int ret = 0;

	memset(&act, 0, sizeof(act));
	memset(&info, 0, sizeof(info));
	memset(&fdinfo, 0, sizeof(fdinfo));

	act.sa_handler = signal_handler;
	printf("\n\tRegistering handler\n");
	sigaction(SIGALRM, &act, NULL);
	printf("\n\tRegistered handler\n");

	alarm(3);
	sleep(3);

	sigemptyset(&set);
        sigaddset(&set, SIGALRM);
	printf("\n\tBlocking SIGALRM\n");
        sigprocmask(SIG_BLOCK, &set, NULL);
        printf("\n\tSIGALRM blocked\n");

	alarm(3);
	printf("\n\twating for signal\n");
	sleep(3);
	sigpending(&set);
	for(i = 1; i < 65; i++)
	{
		if(sigismember(&set, i))
		{
			printf("\n\t pending signal no = %d\n",i);
		}
	}

        sigemptyset(&set);
        sigaddset(&set, SIGALRM);
	alarm(3);
	sigwaitinfo(&set, &info);
	printf("\n\treceived signal %d\n", info.si_signo);
	
        sigemptyset(&set);
        sigaddset(&set, SIGALRM);
	sfd = signalfd(-1, &set, 0);
	alarm(3);
	read(sfd, &fdinfo, sizeof(fdinfo));     
        printf("\n\treceived signal through fd %d\n", fdinfo.ssi_signo);

	sigemptyset(&set);
	sigaddset(&set, SIGALRM);
	printf("\n\tUnblocking SIGALRM\n");
        sigprocmask(SIG_UNBLOCK, &set, NULL);
        printf("\n\tSIGALRM unblocked\n");
	alarm(3);
        sleep(3);

	printf("\n");
}


