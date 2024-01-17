// hang man game in c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

# define MAX_WORDS 10
# define MAX_WORD_LENGTH 20
 // arrays of predefined words for the game
 const char*wordList[MAX_WORDS]= {

    "programming",
    "hangman",
    "computer",
    "software",
    "algorithm",
    "developer",
    "challange",
    "language",
    "creative",
    "coding"

 };
 // function to select a random word from the list

 const char*selectRandomWord(){
    srand(time(NULL));
    return wordList[rand() % MAX_WORDS];

 }
// function to initialise guessed word with underscores
void initializeGuessedWord(char*guessedWord, const char*word)
{
    int lenght= strlen(word);
    for(int i=0;i<lenght;i++)
    {
        guessedWord[i]= '_';

    }
    guessedWord[lenght]= '\0';

}
// function to display the current state of guessed word
void displayGuessedWord( const char*guessedWord)
{
    printf("Current word:%s\n", guessedWord);

}
// function to check if the guessed word is complete
int isWordComplete(const char*guessedWord)
{
    return strchr(guessedWord,'_')==NULL;

}
// function to update guessed word bassed on guessed letter
void updateGuessedWord(char *guessedWord,const char*word, char guessedLetter)
{
    int lenght= strlen(word);
    for(int i=0;i<lenght;i++)
    {
        if(word[i]==guessedLetter)
        {
            guessedWord[i]=guessedLetter;

        }
    }

}
int main()
{
    const char*selectWord=selectRandomWord();
    char guessedWord[MAX_WORD_LENGTH];
    initializeGuessedWord(guessedWord,selectWord);
    int attempts=6; // number of allowed incorrect attmpts
    char guessedLetter[MAX_WORD_LENGTH]; // array to store guessed letters
    int numGuessedLetter=0;
    printf("welcome to hangman!\n");
    while(attempts>0 && ! isWordComplete(guessedWord))

    {
        printf("attempts left: %d", attempts);
        printf("guessed latter:");
        for(int i=0;i<numGuessedLetter;i++)
        {
            printf("%c ",& guessedLetter[i]);

        }
        printf("\n");
        printf("enter a letter");
        char guess;
        scanf("%c",&guess);
        // check if guess letter is already guessed
        int alreadyGuessed=0;
        for(int i=0;i<numGuessedLetter;i++)
        {
            if(guessedLetter[i]==guess)
            {
                alreadyGuessed=1;
                break;
            }
        }
        if(alreadyGuessed)
        {
            printf("you already guessed the letter '%c' . try again \n",guess);
            continue;


        }
        guessedWord[numGuessedLetter++]= guess;
        // check if the guessed letter is in word
        if(strchr(selectWord,guess) != NULL)
        {
            printf("good guess \n");
            updateGuessedWord(guessedWord,selectWord,guess);

        }
        else
        {
            printf("incorrect guess. Try Again");
            attempts--;

        }



    }
    if(isWordComplete(guessedWord))
    {
        printf("Congratulations you printed the right word : %s \n",guessedWord);


    }
    else
    {
        printf("sorry you run out of attempts. The correct word was: %s \n",guessedWord);
    }
return 0;


}