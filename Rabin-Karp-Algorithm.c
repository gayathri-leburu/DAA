
#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet

void rabinKarp(char *text, char *pattern, int q) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;

    // The value of h would be "pow(d, patternLen-1)%q"
    for (i = 0; i < patternLen - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < patternLen; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= textLen - patternLen; i++) {
        // Check the hash values of current window of text and pattern
        // If the hash values match, then only check for characters one by one
        if (p == t) {
            // Check for characters one by one
            for (j = 0; j < patternLen; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == patternLen)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        if (i < textLen - patternLen) {
            t = (d * (t - text[i] * h) + text[i + patternLen]) % q;

            // To handle negative t
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    char text[1000], pattern[1000];
    int q = 101; // A prime number

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
    rabinKarp(text, pattern, q);
    clock_t end_time = clock();

    printf("Runtime: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}


****************************
        OUTPUT
****************************

Scenario	                  Text	                 Pattern	           Runtime
Best Case	                 "aaaaaa"	                 "aaa"	         	21 microseconds
Average Case	           "ababcababcabcabc"	         "abc"		        28 microseconds
Worst Case	              "aaaaaaaaaaaaaa"	         "aaa"		        65 microseconds
