#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if a string is a valid identifier
int isIdentifier(char str[]) {
    // Identifier can't start with a digit
    if (!isalpha(str[0]) && str[0] != '_')
        return 0;

    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_')
            return 0;
    }
    return 1;
}

// Function to check if a string is a valid number
int isNumber(char str[]) {
    int i = 0, dotCount = 0;

    // Optional sign at the beginning
    if (str[i] == '+' || str[i] == '-')
        i++;

    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1) // more than one dot invalid
                return 0;
        }
        else if (!isdigit(str[i])) {
            return 0;
        }
    }
    return (i > 0); // must have at least one digit
}

int main() {
    char input[100];

    printf("Enter a token: ");
    scanf("%s", input);

    if (isIdentifier(input))
        printf("Identifier \n");
    else if (isNumber(input))
        printf("Number \n");
    else
        printf("Invalid Token \n");

    return 0;
}
