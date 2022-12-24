#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
	pid_t pid1 = fork();
	if (pid1 > 0) {
		pid_t pid4 = fork();
		if (pid4 > 0) {
			// parent
			printf("I am parent with pid: %d and my child has pid: %d, %d\n", getpid(), pid1, pid4);
			wait(0);
		} else if (pid4 == 0) {
			printf("I am child 2 with pid: %d and my parent's pid: %d\n", getpid(), getppid());
			pid_t pid5 = fork();
			if (pid5 > 0) {
				pid_t pid6 = fork();
				if (pid6 > 0) {
					wait(0);
				} else if (pid6 == 0) {
					printf("I am child 6 with pid: %d and my parent's pid: %d\n", getpid(), getppid());
				}
				wait(0);
			} else if (pid5 == 0) {
				printf("I am child 5 with pid: %d and my parent's pid: %d\n", getpid(), getppid());
			}
		}
		wait(0);
	} else if (pid1 == 0) {
		printf("I am child 1 with pid: %d and my parent's pid: %d\n", getpid(), getppid());
		pid_t pid2 = fork();
		if (pid2 > 0) {
			pid_t pid3 = fork();
			if (pid3 > 0){
				wait(0);
			} 
			else if (pid3 == 0) {
				printf("I am child 4 with pid: %d and my parent's pid: %d\n", getpid(), getppid());
				wait(0);
			} 
			wait(0);
		} else if (pid2 == 0) {
				printf("I am child 3 with pid: %d and my parent's pid: %d\n", getpid(), getppid());
		}

	}
	sleep(10);
}
