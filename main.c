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
#include <string.h>
#include <time.h>
#include <assert.h>

typedef struct each_word
{
    char * word;
    int occurrences;
} words_t;

words_t * new_word_list (int num_words)
{
    words_t * words = malloc(num_words * sizeof(words_t));
    for (int i = 0; i < num_words; i++)
    {
        words[i].word = malloc(256 * sizeof(char));
        words[i].occurrences = 0;
    }
    return words;
}

void print_line(char * word, int occurrences)
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
    int prev_is_space = 1;
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

int add_unique(words_t * words, char * to_insert, int * insert_index, int array_size)
{
    assert(words);
    for (int i = 0; i < array_size; i++)
    {
        if (words[i].occurrences == 0) break;
        if (strcmp(words[i].word, to_insert) == 0)
        {
            words[i].occurrences++;
            return 1;
        }
    }

    strcpy(words[*insert_index].word, to_insert);
    words[*insert_index].occurrences++;
    (*insert_index)++;
    return 0;
}

void add_words(words_t * words, FILE * input, int word_count)
{
    assert(words);
    char buffer[256];

    int struct_size = 0;

    int struct_index = 0;

    while (fscanf(input, " %255s", buffer) == 1)
    {
        add_unique(words, buffer, &struct_index, word_count);

    }
}


int main(int argc, char * argv[])
{
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Error with opening file.\n");
        return 1;
    }

    int word_count = count_words(input);
    rewind(input);

    printf("WORD COUNT: %d\n", word_count);

    words_t *words = new_word_list(word_count);

    add_words(words, input, word_count);

    int index_to_print = 0;
    while (words[index_to_print].occurrences > 0)
    {
        print_line(words[index_to_print].word, words[index_to_print].occurrences);
        index_to_print++;
    }

    free(words);
    fclose(input);

    return 0;
}


// STEPS:
// https://stackoverflow.com/questions/6105513/need-help-using-qsort-with-an-array-of-structs
// maybe implement arraylist.
// 1. Make array of word length
// 2. Could sort alphabetically first
// 3. qsort
