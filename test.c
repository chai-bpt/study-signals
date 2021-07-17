#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signal)
{
	printf("\n\tsignal handler::signal = %d",signal);
	return;
}

int main(int argvc, char* argv[])
{
	typedef void (*sighandler_t)(int);
	sighandler_t previous_handler = NULL;

	printf("\n\tuser handler::signal_handler = %p\n",signal_handler);
	
	previous_handler = signal(SIGINT, signal_handler);
	printf("\n\tprevious_handler = %p\n",previous_handler);
	sleep(5);

	previous_handler = signal(SIGINT, SIG_IGN);
	printf("\n\tprevious_handler = %p\n",previous_handler);
	sleep(5);

        previous_handler = signal(SIGINT, SIG_DFL);
        printf("\n\tprevious_handler = %p\n",previous_handler);
        sleep(5);

	printf("\n");

}


