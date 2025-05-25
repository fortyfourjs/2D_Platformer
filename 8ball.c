#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void answerQuestion()
{
    const char* answers[20] ={
        "It certainly is", "Thank you", "No doubt", "Go again", "ff", "Go mid", "GG", "Noob", "R", "feeding",
        "ns", "not looking good", "wtf", "123", "Don't bet on it", "Ask again", "Yes", "Most likely", "Lazy", "Maybe"
    };
    printf("\n%s\n", answers[rand() % 20]);
    printf("Would you like to ask me another question?");
    
}
int askQuestion()
{
    char question[100];
    printf("Ask me a question\n");
    fgets(question, sizeof(question), stdin);
}
int main()
{
    srand(time(NULL));

    askQuestion();
    sleep(2);
    printf("thinking...");
    answerQuestion();
    
    return 0;
}
