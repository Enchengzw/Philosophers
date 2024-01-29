#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval tv;

    // Get the current time
    if (gettimeofday(&tv, NULL) != 0) {
        perror("gettimeofday");
        return 1;
    }

	long a = tv.tv_sec * 1000 + (tv.tv_usec / 1000);
    // Print the seconds and microseconds
    printf("Seconds: %ld\n", a);

    return 0;
}
