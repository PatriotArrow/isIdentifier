/*
isIdentifier checks if a given string is a valid C identifier!

first character should be an alphabet or underscore.
second character should be an alphanumeric or underscore
cannot be a reserved word
cannot be longer than 31 characters in length
*/


#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

bool isKeyword(char* str) {
    // list of keywords
    char* keywords[] =
    {
        "auto", "break", "case", "char", "const", "continue","default", "do", "double", 
        "else", "enum", "extern","float", "for", "goto", "if", "int", "long", "register",
        "return", "short", "signed", "sizeof", "static", "struct","switch", "typedef",
        "union", "unsigned", "void", "volatile","while"
    };

    //size of pointer array / size of a pointer = number of pointers ;
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++)
    {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isIdentifier(char* str)
{
    // check if the first is a character is either a letter or underscore
    if( !isalpha(str[0]) && str[0] != '_' )
    {
        return false;        
    }

    //check if rest of the characters are either alphanumeric or underscore
    for (int i = 1 ; i < strlen(str) ; i++)
    {
        if ( !isalnum( str[i] ) && str[i] != '_' )
        {
            return false;
        }
    }

    //check if the identifier is a keyword
    if ( isKeyword(str) )
    {
        return false;
    }

    if (strlen (str) > 31 )
    {
        return false;
    }

    return true;
}

//main function to test IsIdentifier
int main() {
    char testinput[50];
    while (1)
    {
        printf("Enter a string: ");
        scanf("%s", testinput);

        if (isIdentifier(testinput)) {
            printf("%s is a valid identifier\n", testinput);
        } else {
            printf("%s is not a valid identifier\n", testinput);
        }
    }

    return 0;
}