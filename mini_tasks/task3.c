#include <stdio.h>

int main() {
    FILE* file_ptr = NULL;   
    file_ptr = fopen("test.txt", "r");

    FILE* output_file_ptr = NULL;
    output_file_ptr = fopen("output.txt", "w+");

    char buf[50];
    int flag = 1;
    while (fgets(buf, 50, file_ptr) != NULL) {
        flag = 1;
        for(int i = 0; buf[i] != '\n'; ++i) {
            if (buf[i] == 'X') {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            fputs(buf, output_file_ptr);
        }
    }

    fseek(output_file_ptr, 0, SEEK_SET);
    while(fgets(buf, 50, output_file_ptr) != NULL) {
        printf("%s", buf);
    }

    fclose(output_file_ptr);
    fclose(file_ptr);
}