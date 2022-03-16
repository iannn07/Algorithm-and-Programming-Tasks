#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

const int stateLen = 16, wordsLen = 5;
int counter = 0, playCount;
int guessed[stateLen];
char statement[stateLen+1][wordsLen+1];

struct player{
    char name[100]; long int score;
}gamer[10];

int search(int array[], int x, int low, int high){
     while (low <= high){
        int mid = low + (high - low) / 2;
        if (array[mid] == x)
            return mid;
        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    } return -1;
}

int fileRead(){
    FILE *fp = fopen("Data.txt", "r+");
     if(fp == NULL){
        printf("ERROR! Please save it first.");
        exit(1);
    } else{
        while(fscanf(fp, "%s", statement[counter]) != EOF){
            counter++;
        }
    } fclose(fp);
}

//Swapping General
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//Swapping Score
void superSwap(int x, int y){
    struct player temp = gamer[x];
    gamer[x] = gamer[y];
    gamer[y] = temp;
}

//Partition General
int qsPartition(int array[], int low, int high){
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++){
        if (array[j] <= pivot){
        i++;
        swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

//Partition Score
int qScore(int low, int high){
    int pivot = gamer[high].score;
    int i = (low - 1);
    for(int j = low; j < high; j++){
        if(gamer[j].score >= pivot){
            i++; 
            superSwap(i, j);
        }
    }
    superSwap(i+1, high);
    return (i+1);
}

//Quick Sort General
void quickShift(int array[], int low, int high){
    if(low < high){
        int part = qsPartition(array, low, high);
        quickShift(array, low, part - 1);
        quickShift(array, part + 1, high);
    }
}

//Quick Sort Score
void qsScore(int low, int high){
    if(low < high){
        int partS = qScore(low, high);
        qsScore(low, partS - 1);
        qsScore(partS + 1, high);
    }
}

int randTime(){
    srand(time(NULL));
    int random = (rand() % 3);
    return random;
}

int randNum(){
    srand(time(NULL));
    int random = (rand() % 16) + 1;
    return random;
}

int gdWords(int x){
    search(guessed, x, 0, stateLen-1);
}

void header(){
    printf("\t\t\t\t\tTIC TAC TOE GUESSING GAMES\n");
    printf("\t\t\t\t\t    Made by: Pristian Budi\n");
    printf("\t\t\t\t\t\t      Ver. 2.13.09");
    printf("\n\n");
}

void generator(){
    srand(time(NULL)); //To change the words everytime
    counter = 0;
    static const char pass[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    
    printf("\e[1;1H\e[2J"); //Clear Console
    
    header();
    printf("Here's your generated 16 words\n\n");
    printf("\t\t\t- - - - - - - - - - - - - - - - -\n");
    for(int i = counter; i < stateLen; i++){
        for(int j = 0; j < wordsLen; j++){
            statement[counter][j] = pass[rand() % strlen(pass)];
        } 

        //Selection to make a square shape    
        if(i == 3){
            printf("%s |\n", statement[counter]);
            printf("\t\t\t- - - - - - - - - - - - - - - - -\n");
        } else if(i == 7){
            printf("%s |\n", statement[counter]);
            printf("\t\t\t- - - - - - - - - - - - - - - - -\n");
        } else if(i == 11){
            printf("%s |\n", statement[counter]);
            printf("\t\t\t- - - - - - - - - - - - - - - - -\n");
        } else if(i == 0){
            printf("\t\t\t| %s | ", statement[counter]);
        } else if(i % 4 == 0){
            printf("\t\t\t| %s | ", statement[counter]);
        } else{
            printf("%s | ", statement[counter]);
        }
        //This Logic helps for saving files
        counter = i+1;
    } 
    printf("\n\t\t\t- - - - - - - - - - - - - - - - -\n");
}

void saveGen(){
    printf("\n");
    FILE *fp = fopen("Data.txt", "w+");
    char op;
    if(fp == NULL){
        printf("ERROR! The game can't be started.");
        exit(1);
    }
    
    printf("Are you sure to save it? (Y/N) "); getchar();
    scanf("%c", &op);
    
    //Selection for confirmation
    if(op == 'N' || op == 'n'){
        while(op == 'N' || op == 'n'){
            
            printf("\e[1;1H\e[2J"); //Clear Console
            
            srand(time(NULL)); //To change the words everytime
            counter = 0;
            static const char pass[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
            printf("\e[1;1H\e[2J");
            printf("Here's your NEW 16 words\n\n");
            printf("\t\t\t- - - - - - - - - - - - - - - - -\n");
            for(int i = counter; i < stateLen; i++){
                for(int j = 0; j < wordsLen; j++){
                    statement[counter][j] = pass[rand() % strlen(pass)];
                } 

                //Selection to make a square shape    
                if(i == 3){
                    printf("%s |\n", statement[counter]);
                    printf("\t\t\t- - - - - - - - - - - - - - - - -\n");
                } else if(i == 7){
                    printf("%s |\n", statement[counter]);
                    printf("\t\t\t- - - - - - - - - - - - - - - - -\n");
                } else if(i == 11){
                    printf("%s |\n", statement[counter]);
                    printf("\t\t\t- - - - - - - - - - - - - - - - -\n");
                } else if(i == 0){
                    printf("\t\t\t| %s | ", statement[counter]);
                } else if(i % 4 == 0){
                    printf("\t\t\t| %s | ", statement[counter]);
                } else{
                    printf("%s | ", statement[counter]);
                }
                //This Logic helps for saving files
                counter = i+1;
            } 
            printf("\n\t\t\t- - - - - - - - - - - - - - - - -\n\n");
            printf("Are you sure to save it? (Y/N) "); getchar();
            scanf("%c", &op); 
        }
    
    //Saving if Repetition is approved
    for(int i = 0; i < stateLen; i++){
        fprintf(fp, "%s\n", statement[i]);
    } fclose(fp);
    
    printf("\nSuccessfully save the data!\n");
    printf("Enjoy your game!\n\n");

    } else{
        //Saving if directly approve
        for(int i = 0; i < stateLen; i++){
            fprintf(fp, "%s\n", statement[i]);
        } fclose(fp);
            
        printf("\nSuccessfully save the data!\n");
        printf("Enjoy your game!\n\n");
    }
}

void display(){
    char rep = 'N';
    printf("\n");
    while(rep == 'N' || rep == 'n'){
        printf("Here's your words to play\n\n");
        printf("\t\t\t- - - - - - - - - - - - - - - - -\n");
        for(int i = 0; i < stateLen; i++){
            if(i == 3){
                printf("%s |\n", statement[i]);
                printf("\t\t\t- - - - - - - - - - - - - - - - -\n");
            } else if(i == 7){
                printf("%s |\n", statement[i]);
                printf("\t\t\t- - - - - - - - - - - - - - - - -\n");
            } else if(i == 11){
                printf("%s |\n", statement[i]);
                printf("\t\t\t- - - - - - - - - - - - - - - - -\n");
            } else if(i == 0){
                printf("\t\t\t| %s | ", statement[i]);
            } else if(i % 4 == 0){
                printf("\t\t\t| %s | ", statement[i]);
            } else{
                printf("%s | ", statement[i]);
            }
        }
        printf("\n\t\t\t- - - - - - - - - - - - - - - - -\n\n");
        printf("Are you ready to start? (Y/N) "); getchar();
        scanf("%c", &rep);

        printf("\e[1;1H\e[2J"); //Clear Console

    }
}

int displayWords(){
    for(int i = 0; i < stateLen; i++){
        
        int searching = search(guessed, i+1, 0, stateLen-1);
        
        if(i % 4 == 0){
            printf("- - - - - - - - - - - - - - - - -\n|");
        }

        if((i+1) % 4 == 0){
            if(i < 9){
                if(searching == -1){
                    printf("  %02d  |\n", i+1);
                } else{
                    printf(" %s |\n", statement[i]);
                }
            } else{
                if(searching == -1){
                    printf("  %02d  |\n", i+1);
                } else{
                    printf(" %s |\n", statement[i]);
                }
            }
        } else{
            if(i < 9){
                if(searching == -1){
                    printf("  %02d  |", i+1);
                } else{
                    printf(" %s |", statement[i]);
                }
            } else{
                if(searching == -1){
                    printf("  %02d  |", i+1);
                } else{
                    printf(" %s |", statement[i]);
                }
            }
        }
    } printf("- - - - - - - - - - - - - - - - -\n"); return 0;
}

void registry(){
    strcpy(gamer[0].name, "Kompie");
    gamer[0].score = 0;    
    playCount = 1;
    printf("Player Name: "); 
    scanf("%s", gamer[1].name); 
    fflush(stdin);
    gamer[1].score = 0; 
    playCount++;
    printf("\e[1;1H\e[2J"); //Clear Console
}

void saveScore(int id){
    if(playCount != 0){
        FILE *fp = fopen("Score.txt", "a");
        fprintf(fp, "%s|%ld\n", gamer[id].name, gamer[id].score);
        fclose(fp);
        printf("DATA IS SAVED\n");
    } else{
        printf("DATA CAN'T BE SAVED\n");
    }
}

void readScore(){
    playCount = 0;
    FILE *fp = fopen("Score.txt", "r");
    if(fp == NULL){
        printf("ERROR\n");
        exit(1);
    } else{
        while(fscanf(fp,"%[^|]|%ld\n", &gamer[playCount].name, &gamer[playCount].score) != EOF){
            playCount++;
        }
    } fclose(fp); 
    qsScore(0, playCount);
}

void saveTotal(){
    if(playCount != 0){
        FILE *fp = fopen("Score.txt", "w");
        for(int i = 0; i < playCount; i++){
            fprintf(fp, "%s|%ld\n", gamer[i].name, gamer[i].score);
        }
        fclose(fp);
    }
}

void gameStart(){
    //Declaring Variables
    int nWord, nGuess = stateLen-1, max = 0, guessing, turn = 1;
    if(fileRead() != 0 || counter == 0){
        printf("Please generate the words first!\n");
    } else{
        display();
        registry();
        //Computer Turn
        while(guessed[0] == 0){
            nWord = randNum(); //Used for guessing questions
            
            while(gdWords(nWord) != -1){
                printf("Loading.....");
                nWord = randNum();
                printf("\e[1;1H\e[2J"); //Clear Console
            }
        
            displayWords();
        
            //Questions
            printf("\nGuess this word!\n");
            printf("- - - - -\n");
            printf("| %s |\n", statement[nWord-1]);
            printf("- - - - -\n\n");

            //Player Turns
            printf("It's %s turn\n", gamer[turn].name);
            if(turn == 0){ 
                int timer = randTime()*1000;
                Sleep(timer);
                int com = randNum();
                while(gdWords(com) != -1){
                    com = randNum();
                }
                printf("%s choose %02d\n", gamer[turn].name, com);
                guessing = com;
                Sleep(1000);
            } else{
                printf("Answer: ");  
                scanf("%02d", &guessing);
                fflush(stdin);
            }

            //Correction Checking + Sorting For While Function Above
            if(nWord != guessing){
                printf("WRONG ANSWER!\n");
            } else{
                printf("CORRECT\n");
                gamer[turn].score += 10;
                guessed[nGuess] = nWord;
                nGuess--;
                quickShift(guessed, 0, stateLen-1); 
            }

            turn++;
            turn %= 2;

            Sleep(1000);

            printf("\e[1;1H\e[2J"); //Clear Console
        }
        
        //Score Storing
        if(gamer[0].score > gamer[1].score) printf("YOU LOSE\n\n");
        else printf("YOU WIN\n\n");

        //To define who's the winner
        int winner;
        for(int i = 0; i < 2; i++){
            if(max < gamer[i].score){
                max = gamer[i].score;
                winner = i;  
            } 
        }

        printf("CONGRATS %s as the winner of this game with %ld\n\n", gamer[winner].name, gamer[winner].score);
        
        char save;
        printf("Do you want to save the game? (Y/N) ");
        scanf("%c", &save); fflush(stdin);

        if(save == 'Y' || save == 'y'){
            saveScore(winner);
            readScore();
            saveTotal();
        }
    }
}

void displayWin(){
    readScore();
    printf("\nHALL OF FAME\n\n");
    for(int i = 0; i < playCount; i++){
        printf("%d.\t%s\t%ld\n", i+1, gamer[i].name, gamer[i].score);
    } printf("\n\n");
}

int main(){
    int opt;
    header();
    do{
        printf("Here's your menu: \n");
        printf("1. Words Generator\n");
        printf("2. Save Generator Result\n");
        printf("3. START GAME\n");
        printf("4. Display Winner\n");
        printf("0. EXIT\n\n");
        scanf("%d", &opt, printf("Enter your choice: "));
        switch (opt){
        case 1:
            generator(); break;
        case 2:
            saveGen(); break;
        case 3:
            gameStart(); 
            break;
        case 4:
            displayWin(); break;
        default:
            printf("\nThere's no menu %d\n", opt);
            printf("Please select the available menu");
            break;
        }
    } while(opt != 0);
    printf("\e[1;1H\e[2J"); //To Clear Console
    printf("Thank you for Playing :D"); getchar(); getchar();
    return 0;
}