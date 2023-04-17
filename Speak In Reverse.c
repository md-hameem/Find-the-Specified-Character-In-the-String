#include <stdio.h>
#include <string.h>

int main() {
    char string[100];

    // Prompt user to enter a sentence and read input from user
    printf("Enter a sentence (maximum 99 characters): ");
    if (fgets(string, sizeof(string), stdin) == NULL) {
        // If fgets() fails to read input, print an error message and exit program with failure status
        fprintf(stderr, "Input reading failed\n");
        return 1;
    }

    int len = strlen(string);
    int start = len - 1;
    int end = len - 1;

    // Print the reversed sentence
    printf("Reversed sentence: ");
    while (start >= 0) {
        // Find the beginning of the word by scanning backwards for a space character
        while (start >= 0 && string[start] != ' ') {
            start--;
        }

        // Print the word that was found
        for (int i = start + 1; i <= end; i++) {
            printf("%c", string[i]);
        }

        // Print a space character after the word
        printf(" ");

        // Skip over any extra spaces before the next word
        while (start >= 0 && string[start] == ' ') {
            start--;
        }

        // Update the end index to be the last character of the next word
        end = start;
    }

    return 0;
}
