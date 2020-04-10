#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define SEQUENTIAL "sequential_min_max"

int main(int argc, char* argv[]) {
	if (access(SEQUENTIAL, F_OK) == -1) {
		printf("Error: " SEQUENTIAL " not found\n");
		return -1;
	}

	execvp("./" SEQUENTIAL, argv);
	printf("Error: execvp() failed, errno=%d\n", errno);
}