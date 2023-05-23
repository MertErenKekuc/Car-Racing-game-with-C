//210229005 Mert Eren Keküç
//Car Race Game

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

int enemyY[3];
int enemyX[3];
int enemyFlag[3];
char car[4][4] = { {' ','±','±',' '},
                    {'±','±','±','±'},
                    {' ','±','±',' '},
                    {'±','±','±','±'} };

int carPos = WIN_WIDTH/2;
int score = 0;
int best_score = 0;

void gotoxy(int x, int y) {         //Hareketlerin ekrana yansýmasý için hazýr fonksiyon
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void setcursor(int visible)         //Ýmleç görünürlüðünü ayarlar
{
    CONSOLE_CURSOR_INFO cursorInfo;
    HANDLE cursorHandle;
    cursorHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(cursorHandle, &cursorInfo);
    cursorInfo.bVisible = visible;
    SetConsoleCursorInfo(cursorHandle, &cursorInfo);
}

void drawBorder()           //Oyun alaný çerçevesi çizer
{
    for(int i=0; i<SCREEN_HEIGHT; i++) {
        for(int j=0; j<17; j++) {
            gotoxy(0+j,i);
            printf("±");
            gotoxy(WIN_WIDTH-j,i);
            printf("±");
        }
    }
    for(int i=0; i<SCREEN_HEIGHT; i++) {
        gotoxy(SCREEN_WIDTH,i);
        printf("±");
    }
}

void genEnemy(int ind)      //Rastgele düþman konumu oluþturur.
{
    enemyX[ind] = 17 + rand()%(33);
}

void drawEnemy(int ind)      //Düþman aracý çizer
{
    if(enemyFlag[ind] == 1) {
        gotoxy(enemyX[ind], enemyY[ind]);
        printf("****");
        gotoxy(enemyX[ind], enemyY[ind]+1);
        printf(" ** ");
        gotoxy(enemyX[ind], enemyY[ind]+2);
        printf("****");
        gotoxy(enemyX[ind], enemyY[ind]+3);
        printf(" ** ");
    }
}

void eraseEnemy(int ind)        //Düþman aracý siler
{
    if(enemyFlag[ind] == 1) {
        gotoxy(enemyX[ind], enemyY[ind]);
        printf("    ");
        gotoxy(enemyX[ind], enemyY[ind]+1);
        printf("    ");
        gotoxy(enemyX[ind], enemyY[ind]+2);
        printf("    ");
        gotoxy(enemyX[ind], enemyY[ind]+3);
        printf("    ");
    }
}

void resetEnemy(int ind)       //Düþman aracýn konumunu sýfýrlar
{
    eraseEnemy(ind);
    enemyY[ind] = 1;
    genEnemy(ind);
}

void drawCar()      //Kullanýcý arabasýný çizer
{
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            gotoxy(j+carPos, i+22);
            printf("%c", car[i][j]);
        }
    }
}

void eraseCar()     //Kullanýcý arabasýný siler
{
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            gotoxy(j+carPos, i+22);
            printf(" ");
        }
    }
}

int collision(int ind)      //Çarpýþma kontrolü
{

    if(enemyY[ind]+4 >= 23) {
        if(enemyX[ind] + 4 - carPos >= 0 && enemyX[ind] + 4 - carPos < 9) {
            return 1;
        }
    }
    return 0;
}

void gameover()
{
    printf("\a");
    Sleep(40);
    system("cls");
    printf("\n");
    printf("\t\t--------------------------\n");
    printf("\t\t--------------------------\n");
    printf("\t\t-------- GAME OVER -------\n");
    printf("\t\t--------------------------\n");
    printf("\t\t--------------------------\n");
    printf("\t\t----- Your Score: %d -----",score);
    printf("\t\tPress any key to go back to menu.\n");
    printf("\t\t--------------------------\n");
    printf("\t\t----- Best Score: %d -----", best_score);
    getch();

}
void updateScore()      //Skor günceller
{
    gotoxy(WIN_WIDTH + 7, 5);
    printf("Score: %d\n", score);
}

void instructions()
{
    system("cls");
    printf("Instructions");
    printf("\n---------------");
    printf("\n Avoid Cars by moving left or right ");
    printf("\n Press 'a' to move left ");
    printf("\n Press 'd' to move right ");
    printf("\n---------------");
    printf("\n In easy game mode, enemy vehicles come slowly and can be moved more with one click ");
    printf("\n In medium difficulty game mode, enemy vehicles come at normal speed and can be moved less with one click. ");
    printf("\n In hard game mode Enemy vehicles come fast and less action can be taken with one click ");
    printf("\n---------------");
    printf("\n Try to get the best score by continuing without closing the application and your friends will be your rivals.");
    printf("\n---------------");
    printf("\n Press any key to go back to menu ");
    getch();
}

void play1()        //Kolay oyun modu kodlarý
{
    carPos = -1 + WIN_WIDTH/2;
    score = 0;
    enemyFlag[0] = 1;
    enemyFlag[1] = 0;
    enemyY[0] = enemyY[1] = 1;

    system("cls");
    drawBorder();
    updateScore();
    genEnemy(0);
    genEnemy(1);

    gotoxy(WIN_WIDTH + 5, 2);
    printf("Car Race Game");
    gotoxy(WIN_WIDTH + 6, 4);
    printf("----------");
    gotoxy(WIN_WIDTH + 6, 6);
    printf("----------");
    gotoxy(WIN_WIDTH + 7, 12);
    printf(" Control ");
    gotoxy(WIN_WIDTH + 7, 13);
    printf("----------");
    gotoxy(WIN_WIDTH + 5, 14);
    printf("A Key - Left");
    gotoxy(WIN_WIDTH + 5, 15);
    printf("D Key - Left");
    gotoxy(18, 5);
    printf("Press any key to start");
    getch();
    gotoxy(18, 5);
    printf("                      ");

    while(1){
        if(kbhit()){
            char ch = getch();
            if( ch=='a' || ch=='A' ){
                if( carPos > 18 )
                    carPos -= 4;
            }
            if( ch=='d' || ch=='D' ){
                if( carPos < 50 )
                    carPos += 4;
            }
            if(ch==27){
                break;
            }
        }
        printf("\033[96m");
        drawCar();
        printf("\033[0m");

        printf("\033[38;5;226m");
        drawEnemy(0);
        drawEnemy(1);
        printf("\033[0m");

        if( collision(0) == 1 || collision(1) == 1 ){
        gameover();
        getch();
        return;
}
        Sleep(50);
        eraseCar();
        eraseEnemy(0);
        eraseEnemy(1);

        if( enemyY[0] == 10 )
            if( enemyFlag[1] == 0 )
                enemyFlag[1] = 1;

        if( enemyFlag[0] == 1 )
            enemyY[0] += 1;

        if( enemyFlag[1] == 1 )
            enemyY[1] += 1;

        if( enemyY[0] > SCREEN_HEIGHT-7 ){
            resetEnemy(0);
            score++;
            updateScore();
        }
        if( enemyY[1] > SCREEN_HEIGHT-7 ){
            resetEnemy(1);
            score++;
            updateScore();
        }
        if (score > best_score) {
         best_score = score;
      }
    }
    return;
}

void play2()        //Orta zorlukta oyun modu kodlarý
{
    carPos = -1 + WIN_WIDTH/2;
    score = 0;
    enemyFlag[0] = 1;
    enemyFlag[1] = 0;
    enemyY[0] = enemyY[1] = 1;

    system("cls");
    drawBorder();
    updateScore();
    genEnemy(0);
    genEnemy(1);

    gotoxy(WIN_WIDTH + 5, 2);
    printf("Car Race Game");
    gotoxy(WIN_WIDTH + 6, 4);
    printf("----------");
    gotoxy(WIN_WIDTH + 6, 6);
    printf("----------");
    gotoxy(WIN_WIDTH + 7, 12);
    printf(" Control ");
    gotoxy(WIN_WIDTH + 7, 13);
    printf("----------");
    gotoxy(WIN_WIDTH + 5, 14);
    printf("A Key - Left");
    gotoxy(WIN_WIDTH + 5, 15);
    printf("D Key - Right");
    gotoxy(18, 5);
    printf("Press any key to start");
    getch();
    gotoxy(18, 5);
    printf("                      ");

    while(1){
        if(kbhit()){
            char ch = getch();
            if( ch=='a' || ch=='A' ){
                if( carPos > 18 )
                    carPos -= 2;
            }
            if( ch=='d' || ch=='D' ){
                if( carPos < 50 )
                    carPos += 2;
            }
            if(ch==27){
                break;
            }
        }

        printf("\033[96m");
        drawCar();
        printf("\033[0m");

        printf("\033[38;5;208m");
        drawEnemy(0);
        drawEnemy(1);
        printf("\033[0m");

        if( collision(0) == 1 || collision(1) == 1 ){
        gameover();
        getch();
        return;
}
        Sleep(40);
        eraseCar();
        eraseEnemy(0);
        eraseEnemy(1);

        if( enemyY[0] == 10 )
            if( enemyFlag[1] == 0 )
                enemyFlag[1] = 1;

        if( enemyFlag[0] == 1 )
            enemyY[0] += 1;

        if( enemyFlag[1] == 1 )
            enemyY[1] += 1;

        if( enemyY[0] > SCREEN_HEIGHT-7 ){
            resetEnemy(0);
            score++;
            updateScore();
        }
        if( enemyY[1] > SCREEN_HEIGHT-7 ){
            resetEnemy(1);
            score++;
            updateScore();
        }
        if (score > best_score) {
         best_score = score;
      }
    }
    return;
}

void play3()        //Zor oyun modu kodlarý
{
    carPos = -1 + WIN_WIDTH/2;
    score = 0;
    enemyFlag[0] = 1;
    enemyFlag[1] = 0;
    enemyY[0] = enemyY[1] = 1;

    system("cls");
    drawBorder();
    updateScore();
    genEnemy(0);
    genEnemy(1);

    gotoxy(WIN_WIDTH + 5, 2);
    printf("Car Race Game");
    gotoxy(WIN_WIDTH + 6, 4);
    printf("----------");
    gotoxy(WIN_WIDTH + 6, 6);
    printf("----------");
    gotoxy(WIN_WIDTH + 7, 12);
    printf(" Control ");
    gotoxy(WIN_WIDTH + 7, 13);
    printf("----------");
    gotoxy(WIN_WIDTH + 5, 14);
    printf("A Key - Left");
    gotoxy(WIN_WIDTH + 5, 15);
    printf("D Key - Left");
    gotoxy(18, 5);
    printf("Press any key to start");
    getch();
    gotoxy(18, 5);
    printf("                      ");

    while(1){
        if(kbhit()){
            char ch = getch();
            if( ch=='a' || ch=='A' ){
                if( carPos > 18 )
                    carPos -= 2;
            }
            if( ch=='d' || ch=='D' ){
                if( carPos < 50 )
                    carPos += 2;
            }
            if(ch==27){
                break;
            }
        }
        printf("\033[96m");
        drawCar();
        printf("\033[0m");

        printf("\033[31m");
        drawEnemy(0);
        drawEnemy(1);
        printf("\033[0m");

        if( collision(0) == 1 || collision(1) == 1 ){
        gameover();
        getch();
        return;
}
        Sleep(26);
        eraseCar();
        eraseEnemy(0);
        eraseEnemy(1);

        if( enemyY[0] == 10 )
            if( enemyFlag[1] == 0 )
                enemyFlag[1] = 1;

        if( enemyFlag[0] == 1 )
            enemyY[0] += 1;

        if( enemyFlag[1] == 1 )
            enemyY[1] += 1;

        if( enemyY[0] > SCREEN_HEIGHT-7 ){
            resetEnemy(0);
            score++;
            updateScore();
        }
        if( enemyY[1] > SCREEN_HEIGHT-7 ){
            resetEnemy(1);
            score++;
            updateScore();
        }
         if (score > best_score) {
         best_score = score;
      }
    }
    return;
}

int main()
{
    setcursor(0);
    srand((unsigned)time(NULL));

    char choice;
    do {
        system("cls");

        for(int i=0; i<22; i++) {
            for(int j=0; j<2; j++) {
                gotoxy(j+16, i+3);
            printf("*");
            }
        }

         for(int i=0; i<22; i++) {
            for(int j=0; j<2; j++) {
                gotoxy(j+47, i+3);
            printf("*");
            }
        }
        printf("\033[96m");
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                gotoxy(j+30, i+20);
            printf("%c", car[i][j]);
            }
        }
        printf("\033[0m");

        printf("\033[92m");
        gotoxy(20,5);
        printf("-------------------------");
        gotoxy(19,6);
        printf("|      CAR RACE GAME      |");
        gotoxy(20,7);
        printf("-------------------------");
        printf("\033[38;5;226m");
        gotoxy(20,9);
        printf("1. Start Game  -(Easy)-");
        printf("\033[0m");
        printf("\033[38;5;208m");
        gotoxy(20,10);
        printf("2. Start Game -(Medium)-");
        printf("\033[0m");
        printf("\033[31m");
        gotoxy(20,11);
        printf("3. Start Game  -(Hard)-");
        printf("\033[0m");
        gotoxy(20,13);
        printf("4. Instructions");
        gotoxy(20,14);;
        printf("5. Quit");
        gotoxy(20,16);
        printf("Select option: ");
        choice = getch();

        switch (choice) {
            case '4':
                instructions();
                break;
            case '1':
                play1();
                break;
            case '2':
                play2();
                break;
            case '3':
                play3();
                break;
            case '5':
                return 0;
            default:
                printf("\n\t   Invalid choice. Press any key to continue...");
                getch();
                break;
        }
    } while (1);
    return 0;
}
