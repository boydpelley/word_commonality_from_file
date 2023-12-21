# Word Commonality
  This program takes a .txt file on the command line, and reads over the file word by word, ordering them from most common to least common. 
It outputs asterisk characters next to the words, representing the amount of occurrences. The program also displays the total word count from the file, 
and the asterics are displayed all in-line with one another so the histogram is better represented.

## Processing
  It starts by opening the file, and counting how many words exist within the file by checking for whitespace characters (accounting for double 
or greater amount in a row). 

  With the word count, it initalizes a dynamically sized array of word structs, which contain the word and the number of occurrences. Two 
functions add the words to the array, based on whether the array reaches an empty spot (i.e. no word exists at certain index), and/or it also 
doesn't exist within the array of words. If it does exist increase the occurrences, otherwise add the word at the specified index. 

  Using qsort(), it sorts it from highest number of occurences to lower.
  
  After all of the words are sorted, a function then determines the maximum length of a word, which then is used in the print function, 
which subtracts the maximum length from the current word length to determine how many spaces should be printed before the asterisk 
characters.

## Input Parameters
- File reads in a maximum line size of 255 characters at a time.
- File must be a .txt file or equivalent.

### Future Considerations
- Prompt user if they wanted to make an output file instead.
- Sort alphabetically for words that have the same number of occurrences.
