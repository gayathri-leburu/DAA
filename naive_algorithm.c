#include <stdio.h>
#include <string.h>
#include <time.h>

void naiveStringMatch(char *text, char *pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int i, j;

    for (i = 0; i <= textLen - patternLen; i++) {
        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == patternLen) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[1000], pattern[1000];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter pattern: ");
    fgets(pattern, sizeof(pattern), stdin);

    // Remove newline characters
    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    clock_t start_time = clock();
    naiveStringMatch(text, pattern);
    clock_t end_time = clock();

    printf("Runtime: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}



******************************************
                 OUTPUT
******************************************

Scenario	             Text	                Pattern	             Runtime
  
Best Case	           "aaaaaa"	               "aaa"	           17 microseconds
  
Average Case	   "ababcababcabcabc"	         "abc"	           25 microseconds
  
Worst Case	      "aaaaaaaaaaaaaa"	         "aaa"	           48 microseconds
			
			
			

