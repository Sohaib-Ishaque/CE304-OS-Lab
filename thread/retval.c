#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

struct student {
	int number;
	char* name;
};

void *print_student(void *input) {
	struct student *std = (struct student *)input;
	printf("Hello %s! Your student ID is %d\n", std->name, std->number);

	pthread_exit((void *)10l);
}

int main() {
	struct student mohammad;
	mohammad.number = 9231058;
	mohammad.name = "Mohammad";

	pthread_t thread;

	pthread_create(&thread, NULL, print_student, (void *)&mohammad);



	void *retval;


	pthread_join(thread, &retval);
	printf("Exit: %ld\n", (long)retval);
}
