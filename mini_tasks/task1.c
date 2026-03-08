#include <stdio.h>

int main() {
    FILE* file_ptr = NULL;
    // file_ptr = fopen("test.txt", "w");

    // char* arr = "Hello World!\n";
    // fputs(arr, file_ptr);

    // fclose(file_ptr);
    // file_ptr = NULL;

    char buf[50];
    
    file_ptr = fopen("test.txt", "r");

    while(fgets(buf, 50, file_ptr) != NULL) {
        printf("%s", buf);
    }

    fclose(file_ptr);
}