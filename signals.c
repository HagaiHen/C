#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void sig_handler(int signum)
{
	int i=5;
	int j=0;
	int k;
	switch (signum) {
		case SIGCHLD:
			printf("I am in SIGCHLD\n");
			fflush(stdout);
			raise(SIGUSR1);
		case SIGUSR1: 
			printf("I am in SIGUSR1\n");
			fflush(stdout);
			k=i/j;
			printf("lalala\n");
			fflush(stdout);
			break;
		case SIGFPE:
			printf("I am in SIGFPE\n");
			fflush(stdout);
			int * p = NULL;
			*p = 0;
		case SIGSEGV:
			printf("I am in SIGSEGV\n");
			fflush(stdout);
			alarm(2);
			sleep(1);
			pause();
		case SIGTERM:
			printf("I am in SIGTERM\n");
			fflush(stdout);
			exit(1); 
			
		case SIGALRM:
			printf("I am in SIGALRM\n");
			fflush(stdout);
			kill(getpid(), SIGTERM);		
			}
				
}

int main()
{
	int status;
		signal (SIGALRM, sig_handler);
	signal (SIGQUIT, sig_handler);
	signal (SIGCONT, sig_handler);
	signal (SIGSTOP, sig_handler);
	signal (SIGTERM, sig_handler);
	signal (SIGSEGV, sig_handler);
	signal (SIGFPE, sig_handler);
	signal (SIGCHLD, sig_handler);
	signal (SIGUSR1, sig_handler);
	signal (SIGUSR2, sig_handler);
	
	
	if (!(fork())) {
		exit(1);
	}
	wait(&status);

}
