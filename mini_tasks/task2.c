#include <stdio.h>

int main() {
    FILE* file_ptr = NULL;

    char buf[50];

    file_ptr = fopen("test.txt", "r");

    fgets(buf, 50, file_ptr);
    printf("%s", buf);

    fseek(file_ptr, 0, SEEK_SET);
    if (!(ftell(file_ptr) == SEEK_SET)) {
        printf("failed to fseek\n");
        return 0;
    }

    fgets(buf, 50, file_ptr);
    printf("%s", buf);

    fclose(file_ptr);
}