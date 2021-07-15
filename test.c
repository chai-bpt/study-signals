#include <stdio.h>
#include <unistd.h>

int main(int argvc, char* argv[])
{
	printf("\n\tmy pid = %d",getpid());
	while(1)
	{
		printf("\n\tlooping");
		sleep(2);
	}
}
