#include <stdio.h>
#include <stdlib.h>

// Function to write to a file
void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("No Such File Exists.\n");
        return;
    }

    printf("Enter text to write to the file (end by pressing Enter):\n");
    char input[1000]; // Buffer for input
    getchar();
    fgets(input, sizeof(input), stdin); // Getting input from user
    fputs(input, file);                 // Writing input in file

    printf("Data written successfully to %s\n", filename);
    fclose(file); //closing the file
}

// Function to read a file
void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("No Such File Exists.");
        return;
    }

    printf("Contents of the file %s:\n", filename);
    char ch;
    while ((ch = fgetc(file)) != EOF) { //getting char from file until it is reaches the end 
        putchar(ch);
    }
    fclose(file);
}

// Function to append to a file
void appendFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file for appending");
        return;
    }

    printf("Enter text to append to the file (end by pressing Enter):\n");
    char input[1000]; // Buffer for input
    getchar();        // Clear input buffer
    fgets(input, sizeof(input), stdin); //  Getting input from user
    fputs(input, file);                 // Appending to the file

    printf("Data appended successfully to %s\n", filename);
    fclose(file);
}

int main() {
    char filename[100];
    int choice;

    printf("Enter the filename: ");
    scanf("%s", filename);

    do {
        printf("\nFile Operations Menu:\n");
        printf("1. Write to a file\n");
        printf("2. Read from a file\n");
        printf("3. Append to a file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeFile(filename);
                break;
            case 2:
                readFile(filename);
                break;
            case 3:
                appendFile(filename);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
