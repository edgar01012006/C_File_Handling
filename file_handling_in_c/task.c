#include <stdio.h>
#include <string.h>

void printChoice() {
    printf("1: Take File1\n");
    printf("2: Take File2\n");
    printf("3: Take File1 & Skip File2\n");
    printf("4: Take File2 & Skip File1\n");
}

void file_comparison(FILE* ptr1, FILE* ptr2, FILE* tmpptr) {
    const int size = 50;

    char buf1[size] = {};
    char buf2[size] = {};

    int user_input = 0;

    int flush_flag1 = 1;
    int flush_flag2 = 1;

    while (feof(ptr1) == 0 || feof(ptr2) == 0) {

        if (flush_flag1 == 1) {
            memset(buf1, 0, size);
            fgets(buf1, size, ptr1);
        }
        if (flush_flag2 == 1) {
            memset(buf2, 0, size);
            fgets(buf2, size, ptr2);
        }

        if (memcmp(buf1, buf2, size) == 0) {
            fputs(buf1, tmpptr);
            flush_flag1 = 1;
            flush_flag2 = 1;
        }
        else {
            printf("File1 line: %s", buf1);
            printf("File2 line: %s", buf2);
            printChoice();

            scanf("%d", &user_input);
            
            switch(user_input) {
                case 1:
                    fputs(buf1, tmpptr);
                    flush_flag2 = 0;        
                    flush_flag1 = 1;
                    break;
                case 2:
                    fputs(buf2, tmpptr);
                    flush_flag1 = 0;
                    flush_flag2 = 1;
                    break;
                case 3:
                    fputs(buf1, tmpptr);
                    flush_flag1 = 1;
                    flush_flag2 = 1;
                    break;
                case 4:
                    fputs(buf2, tmpptr);
                    flush_flag1 = 1;
                    flush_flag2 = 1;
                    break;
                default:
                    printf("wrong input, exiting program\n");
                    return;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    FILE* ptr1 = NULL;
    FILE* ptr2 = NULL;
    FILE* tmpptr = NULL;

    ptr1 = fopen(argv[1], "r");
    if (ptr1 == NULL) {
        perror("Failed to open the file");
        return 0;
    }

    ptr2 = fopen(argv[2], "r");
    if (ptr2 == NULL) {
        perror("Failed to open the file");
        return 0;
    }

    tmpptr = fopen("tmpfile.txt", "w");
        if (tmpptr == NULL) {
        perror("Failed to open the file");
        return 0;
    }
    
    file_comparison(ptr1, ptr2, tmpptr);

    fclose(tmpptr);
    fclose(ptr2);
    fclose(ptr1);
}
