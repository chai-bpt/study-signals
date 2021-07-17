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
	printf("\n\tmy pid = %d",getpid());

	signal(SIGINT, signal_handler);

	while(1)
	{
		printf("\n\tlooping");
		sleep(2);
	}
}
