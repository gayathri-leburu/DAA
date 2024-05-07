#include <stdio.h>
#include <string.h>
#include <time.h>

#define NO_OF_CHARS 256

int getNextState(char *pattern, int patternLen, int state, int x) {
    // If the character c is same as next character in pattern, then simply increment state
    if (state < patternLen && x == pattern[state])
        return state + 1;

    int nextState, i;

    // ns stores the result which is next state
    // ns finally contains the longest prefix which is also suffix in "pat[0..state-1]c"
    for (nextState = state; nextState > 0; nextState--) {
        if (pattern[nextState - 1] == x) {
            for (i = 0; i < nextState - 1; i++) {
                if (pattern[i] != pattern[state - nextState + 1 + i])
                    break;
            }
            if (i == nextState - 1)
                return nextState;
        }
    }

    return 0;
}

void computeTF(char *pattern, int patternLen, int TF[][NO_OF_CHARS]) {
    int state, x;
    for (state = 0; state <= patternLen; state++)
        for (x = 0; x < NO_OF_CHARS; x++)
            TF[state][x] = getNextState(pattern, patternLen, state, x);
}

void finiteAutomaton(char *text, char *pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int TF[patternLen + 1][NO_OF_CHARS];
    int i, state = 0;

    computeTF(pattern, patternLen, TF);

    for (i = 0; i < textLen; i++) {
        state = TF[state][text[i]];
        if (state == patternLen)
            printf("Pattern found at index %d\n", i - patternLen + 1);
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
    finiteAutomaton(text, pattern);
    clock_t end_time = clock();

    printf("Runtime: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}



******************************
         OUTPUT
******************************

Scenario	                  Text	           Pattern	             Runtime
Best Case	                "aaaaaa"	           "aaa"	               19 microseconds
Average Case	        "ababcababcabcabc"	     "abc"	               29 microseconds
Worst Case	           "aaaaaaaaaaaaaa"	       "aaa"	               33 microseconds

