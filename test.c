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
	
	signal(SIGINT, signal_handler);
	printf("\n\tsignal handler registered\n");
	sleep(10);

	printf("\n");
}


