#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Defining the  keywords
char *keywords[] = {"int", "float", "if", "else", "while", "return", "void", "char"};
int keywordCount = sizeof(keywords) / sizeof(keywords[0]);

// Function to check if a word is a keyword
int isKeyword(char *word) {
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    char operators[] = {'+', '-', '*', '/', '=', '<', '>', '!', '&', '|'};
    int opCount = sizeof(operators) / sizeof(operators[0]); //calculating the number of elements in the operators array.
    for (int i = 0; i < opCount; i++) {
        if (ch == operators[i]) {
            return 1;
        }
    }
    return 0;
}

//Function to process the input file
void lexicalAnalysis(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    char ch;
    char buffer[100];
    int bufferIndex = 0;

    printf("Lexical Analysis:\n\n");

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) { // If the character is a letter, start forming an identifier/keyword
            buffer[bufferIndex++] = ch;
        } else if (isdigit(ch)) { // If the character is a digit
            buffer[bufferIndex++] = ch;
        } else {
            if (bufferIndex > 0) {
                buffer[bufferIndex] = '\0';
                if (isKeyword(buffer)) {
                    printf("Keyword: %s\n", buffer);
                } else {
                    printf("Identifier: %s\n", buffer);
                }
                bufferIndex = 0;
            }

            if (isOperator(ch)) {
                printf("Operator: %c\n", ch);
            } else if (isspace(ch)) {
                continue; // Skip whitespace
            } else if (ispunct(ch) && !isOperator(ch)) {
                printf("Punctuation: %c\n", ch);
            }
        }
    }

    if (bufferIndex > 0) {
        buffer[bufferIndex] = '\0';
        if (isKeyword(buffer)) {
            printf("Keyword: %s\n", buffer);
        } else {
            printf("Identifier: %s\n", buffer);
        }
    }

    fclose(file);
}

int main() {
    char filename[100];
    printf("Enter the input file name: ");
    scanf("%s", filename);

    lexicalAnalysis(filename);

    return 0;
}
