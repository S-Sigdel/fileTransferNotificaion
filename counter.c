#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    while (1==1) {
        FILE *fp;
        char buffer[100];
        int file_count;
        int final_file_count;
        //take input
        printf("What is the total number of files that should be in this directory? \n Find it out using the following command 'find <directory> -type f | wc -l' ");
        scanf("%d", &final_file_count)

        //finds total files in current(target) directory
        fp = popen("find . -type f | wc -l", "r"); //change the . to the target directory
        if (fp == NULL) {
            perror("popen");
            exit(1);
        }

        //output in buffer
        if (fgets(buffer, sizeof(buffer), fp) == NULL) {
            perror("fgets");
            exit(1);
        }
        pclose(fp);
        buffer[strcspn(buffer, "\n")] = '\0';
        //buffer to integer
         file_count = atoi(buffer);
		    float percentile;
		    percentile = (((float)file_count/(float)final_file_count)*100);
        // Print the current file count
        printf("Current file count: %d\n And the current percentile is: %.2f \n", file_count, percentile);

        if (file_count == final_file_count) {
            system("dunstify transfercomplete");
            break;  
        }
        sleep(5); 
    }

    return 0;
}
