#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

// Function to draw the hangman based on incorrect guesses
void hangmandraw(int incorrectguess) {
    printf(" +---+\n");
    printf(" |   |\n");
    if (incorrectguess >= 1) {
        printf(" O   |\n");
    } else {
        printf("     |\n");
    }
    if (incorrectguess >= 2) {
        printf(" |   |\n");
    } else {
        printf("     |\n");
    }
    if (incorrectguess >= 3) {
        printf(" |   |\n");
    } 
    if (incorrectguess >= 4) {
        printf(" |   |\n");
    } else {
        printf("     |\n");
    }
    if (incorrectguess >= 5) {
        printf("/|\\  |\n");
    } 
    if (incorrectguess >= 6) {
        printf(" |   |\n");
    } 
    if (incorrectguess >= 7) {
        printf(" |   |\n");
    } 
    if (incorrectguess >= 8) {
        printf(" |   |\n");
    } 
     if (incorrectguess >= 9) {
        printf(" |   |\n");
    } 
    if (incorrectguess >=10) {
        printf("/|\\  |\n");  
    } else {
        printf("     |\n");
    }
    printf("=======\n");
}

int main() {
    // 1. Word bank

    const char *wordlist[] = {
        "programming",
        "keyboard",
        "computer",
        "artificial intelligence",
        "operating system",
        "tablet",
        "smartphone",
        "architecture",
        "array",
        "earphone",
        "memory",
        "server",
        "devops",
        "engineer",
        "software",
        "graphics",
        "application",
        "network",
        "system on chip",
        "cable",
        "charger",
        "windows",
        "macos",
        "ios",
        "android",
        "linux",
        "discrete",
        "library",
        "python",
        "ruby on rails",
        "java",
        "unix",
        "central processing unit",
        "graphical processing unit",
        "image signalling processor",
        "modem",
        "router",
        "semiconductor",
        "context window",
        "machine learning",
        "agentic",
        "tensorflow",
        "pytorch",
        "kubernetes",
        "docker",
        "javascript",
        "typescript",
        "nextjs",
        "react",
        "mandatory access control",
        "packet filter",
        "virtual private network",
        "domain name system",
        "dataset",
        "version control",
        "transport layer security",
        "secure shell",
        "postgresql",
        "mysql",
        
    };
    int totalword=sizeof(wordlist)/sizeof(wordlist[0]);
    srand(time(NULL));

    int totalround=3;
    int currentscore=0;
    printf("===============================\n");
    printf("Welcome to the Ultimate Technology Hangman Challenge!\n In this game, you have to win three rounds to become the champion! \n Failing to win a round will result in losing the game.\n");
    printf("===============================\n");

    for (int round=1; round <=totalround; round++) {
    printf("\n>>> Round %d of %d <<<\n", round, totalround);
    
    int randomindex=rand() % totalword;
    const char *secretword = wordlist[randomindex];
    int wordlength = strlen(secretword);
    
    char hiddenword[200];
    for (int i = 0; i < wordlength; i++) {
        hiddenword[i] = (secretword[i] == ' ') ? ' ' : '_';
    }
    hiddenword[wordlength] = '\0';
    
    char guess;
    int incorrectguess = 0;
    int maxincorrectguess = 10;  
    int haswon = 0;
    
    while (incorrectguess < maxincorrectguess) {
        hangmandraw(incorrectguess);
        printf("The hidden word is: %s\n", hiddenword);
        printf("Incorrect guesses: %d/%d\n", incorrectguess, maxincorrectguess);
        printf("Enter your guess: ");
        scanf(" %c", &guess);
        guess = tolower(guess);
        
        int found = 0;
        for (int i = 0; i < wordlength; i++) {
            if (secretword[i] == guess) {
                hiddenword[i] = guess;
                found = 1;
            }
        }
        
        if (!found) {
            incorrectguess++;
            printf("Sorry, '%c' is not in the word!\n", guess);
        } else {
            printf("Good job! '%c' is in the word!\n", guess);
        }
        
        // Check if won
        haswon = 1;
        for (int i = 0; i < wordlength; i++) {
            if (secretword[i] != ' ' && hiddenword[i] == '_') {
                haswon = 0;
                break;
            }
        }
        
        if (haswon) break;  
    }

    hangmandraw(incorrectguess);
    
    if (haswon) {
        printf("Word: %s\n", hiddenword);
        printf("Congratulations, you won this round!\n");
        currentscore++;
    } else {
        printf("You lost the game!\n");
        printf("The word was: %s\n", secretword);
        printf("Final Score: %d/%d rounds cleared.\n", currentscore, totalround);
        return 0;  
    }
}


    printf("\n=========================================\n");
    printf("🏆 CONGRATULATIONS! YOU ARE THE CHAMPION! 🏆\n");
    printf("You cleared all %d rounds!\n", totalround);
    printf("=========================================\n");

    printf("Press Enter to exit: ");
    getchar();
    getchar();
    
    return 0;
}
