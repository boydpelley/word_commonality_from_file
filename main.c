/******************************************************************************
 * Author: Boyd Pelley
 * Email: boyd@pelley.ca
 * Started: 12 December 2023
 * ===========================================================================
 * Description: This program will take a .txt file from the command line, and
 * will be processed, counting the number of words in the file, then
 * it will determine the least common to most common, printing out a
 * histogram along with the word next to it.
 *****************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

typedef struct each_word
{
    char * word;
    int occurrences;
} words_t;

void print_lines(char * word, int occurrences)
{
    // Maybe should also determine the longest word and then print out after the longest word length as well
    printf("%s: ", word);
    for (int i = 0; i < occurrences; i++)
    {
        printf("*");
    }
    printf("\n");
}

int count_words(FILE *to_read)
{
    int num_words = 0;

    int character;
    int prev_is_space = 0;

    while ((character = fgetc(to_read)) != EOF)
    {
        if (isspace(character))
        {
            prev_is_space++;
        }
        else
        {
            if (prev_is_space) num_words++;
            prev_is_space = 0;
        }
    }

    return num_words;
}

int main(int argc, char * argv[])
{

    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Error with opening file.\n");
        return 1;
    }

    int word_count = count_words(input);

    words_t words[word_count];


}


// STEPS:
// https://stackoverflow.com/questions/6105513/need-help-using-qsort-with-an-array-of-structs
// maybe implement arraylist.
// 1. Make array of word length
// 2. Could sort alphabetically first
// 3. qsort
