#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int cash = 5000;
int price_spit = 300;
int koef = 100;
int prize, count = 0;
int arr[3];

void Combination_num(){
    int i;
    for(i = 0; i < 3; i++){
        arr[i] = rand() % 8;
    }
}

int Jackpot(){
    prize = 0;
    if (arr[0] <= 4 && arr[0] == arr[1] == arr[2]){
        prize = (arr[0] + 1) * koef;
    }
    if (arr[0] > 4){
        if((arr[0] == 6) && (arr[1] == 6) && (arr[2] == 6))
        {
            prize = -2000;
            return 0;
        } 
        if((arr[0] == 7) && (arr[1] == 7) && (arr[2] == 7)) return 1;
        prize = (arr[0] + 1) * koef;
    }

    return 0;
}

void OutPut(){
    char operation = '+';
    printf("<<<Welcome to the lottery>>>\n");
    printf("\nScroll cost - %d credits", price_spit);
    printf("\nNum of rotations - %d ", count);
    if(count != 0){
        if(prize < 0){ operation = '-';}
        printf("\nYour spin prize: %d credits!!!\n", prize);
        printf("\n  _______________       |History balance:");
        printf("\n |     Casino!   |      |balance: %7.d", cash);
        printf("\n |...............|      |cost_spin: -%d", price_spit);
        printf("\n |=|-%d-|-%d-|-%d-|=|      |prize:     %c%d",arr[0], arr[1], arr[2], operation, prize);
        printf("\n |...............|      |_________________");
        cash = cash - price_spit + prize;
        printf("\n |_______________|      |total: %9d\n", cash);
    }
    count++;
    sleep(4);
    system("clear"); 
}

void Start_spin(){
    while ((cash - price_spit) >= 0) {
        OutPut();
        Combination_num();
        if (Jackpot() == 1) {
            printf("JACKPOT!!! YOU WIN!!!\n");            
            exit(1);
        }
    }  
    printf("YOU LOSE!!! You don't have enough money!\n");  
    exit(0);
}

int main(){

    srand(time(NULL));
    Start_spin();
    return 0;

}