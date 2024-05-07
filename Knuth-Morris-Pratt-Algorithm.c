#include <stdio.h>
#include <string.h>
#include <time.h>

void computeLPSArray(char *pattern, int patternLen, int *lps) {
    int len = 0; // Length of the previous longest prefix suffix

    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < patternLen) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // This is tricky. Consider the example AAACAAAA and i = 7.
                len = lps[len - 1];

                // Also, note that we do not increment i here
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *text, char *pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);

    // Create lps[] that will hold the longest prefix suffix values for pattern
    int lps[patternLen];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pattern, patternLen, lps);

    int i = 0; // index for text[]
    int j = 0; // index for pattern[]

    while (i < textLen) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == patternLen) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }

        // Mismatch after j matches
        else if (i < textLen && pattern[j] != text[i]) {
            // Do not match lps[0..lps[j-1]] characters, they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
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
    KMPSearch(text, pattern);
    clock_t end_time = clock();

    printf("Runtime: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}

************************
        OUTPUT
************************

Scenario	                     Text	                Pattern	                  Runtime (in microseconds)
Best Case	                   "aaaaaa"	               "aaa"	                       16
Average Case	            "ababcababcabcabc"	       "abc"	                       20
Worst Case	                "aaaaaaaaaaaaaa"	       "aaa"	                       40

