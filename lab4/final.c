#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
	pid_t pid1 = fork();
	printf("Hello world!\n");
	if (pid1 > 0) {
		printf("I am parent with pid: %d and my child has pid: %d\n", getpid(), pid1);
		pid_t pid4 = fork();
		if (pid4 > 0) {
			// parent
		} else if (pid4 == 0) {
			printf("I am child with pid: %d and my parent's pid: %d\n", getpid(), getppid());
			pid_t pid5 = fork();
			if (pid5 > 0) {
				wait(0);
			} else if (pid5 == 0) {
				printf("I am child with pid: %d and my parent's pid: %d\n", getpid(), getppid());
			}
			pid_t pid6 = fork();
			if (pid5 > 0 && pid6 > 0) {
				wait(0);
			} else if (pid5 > 0 && pid6 == 0) {
				printf("I am child with pid: %d and my parent's pid: %d\n", getpid(), getppid());
			}
		}
		wait(0);
	} else if (pid1 == 0) {
		printf("I am child with pid: %d and my parent's pid: %d\n", getpid(), getppid());
		pid_t pid2 = fork();
		if (pid2 > 0) {
			// printf("I am parent with pid: %d and my child has pid: %d\n", getpid(), pid2);
			wait(0);
		} else if (pid2 == 0) {
			printf("I am child with pid: %d and my parent's pid: %d\n", getpid(), getppid());
		}
		pid_t pid3 = fork();
		if (pid2 > 0 && pid3 > 0){
			// printf("I am parent with pid: %d and my child has pid: %d\n", getpid(), pid3);
			wait(0);
		} 
		else if (pid2 > 0 && pid3 == 0) {
			printf("I am child with pid: %d and my parent's pid: %d\n", getpid(), getppid());
		}
	}
			sleep(10);


}
