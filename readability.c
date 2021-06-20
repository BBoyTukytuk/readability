#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int calc_sen(string text); // We want to get the string and count using '.', '!', '?'
int calc_words(string text); // We want to count using spaces, but add 1 to count the last word
int calc_letters(string text); // Make sure you use alpha to detect what is an letter
int calc_grade(int sentences, int words, int letters); // We want to get the integer of that is in each

int main(void)
{
    string text = get_string("Text: "); // Get input words from user as a string

    int sentences = calc_sen(text); // the final interger from our function will be inside sentences
    int words = calc_words(text);
    int letters = calc_letters(text);
    int grade = calc_grade(sentences, words, letters);// we are now pulling the info from the result from functions not text

    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}

int calc_sen(string text)
{
    int num_sentences = 0; // This is to keep track of the sentences
    for (int i = 0, characters = strlen(text); i < characters; i++) // strlen word refers to the argument that was passed
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') // This is how you can search for specific things
        {
            num_sentences += 1 ;
        }

    }
    return num_sentences; // this is the output of int calc_sen which equals sentences
}

int calc_words(string text)
{
    int num_words = 1;
    for (int i = 0, characters = strlen(text); i < characters; i++) // strlen word refers to the argument that was passed
    {
        if (text[i] == ' ')
        {
            num_words += 1 ;
        }
    }
    return num_words; // this is the output of int calc_words which equals words
}

int calc_letters(string text)

{
    int num_letters = 0;
    for (int i = 0, characters = strlen(text); i < characters; i++) // strlen word refers to the argument that was passed
    {
        if (isalpha(text[i])) // Is Alpha is how we determine whether it is an alphabet or not
        {
            num_letters += 1 ;
        }
    }
    return num_letters; // this is the output of int calc_letters which equals letters
}

int calc_grade(int sentences, int words, int letters) // we are going to pull from the integer from each functions
{

    float S = ((sentences / (float)words) * 100); //to find the average of words per sen, we use float to keep the decimal points
    float L = ((letters / (float)words) * 100); //finding the average of letters per words

    return round(0.0588 * L - 0.296 * S - 15.8);
}
