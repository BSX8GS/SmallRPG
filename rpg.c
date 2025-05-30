#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int damage = 3;
int HP = 10;

#ifdef ATTACK
void attack(int *enemyHP) {
    printf("\nYou attacked the enemy.");
    if(*enemyHP - damage >= 0){
        *enemyHP = *enemyHP - damage;
    } else {
        *enemyHP = 0;
    }
    printf("\nEnemy has %d HP left.", *enemyHP);
}
#endif

int main() {
    srand(time(NULL));
    char input;
    //random number between 5 and 8 (inclusive)
    int enemyHP = rand() % 8 + 5;

    printf("Actions:");
    printf("\na = attack the enemy with %d damage", damage);
    printf("\nx = exit");
    printf("\nIn case of entering a character, that is not among these, you skip your turn.\n");
    
    while(enemyHP > 0 && HP > 0) {
        printf("\nYOUR TURN");
        printf("\nEnter a character: ");
        scanf(" %c", &input);  
        switch (input) {
        case 'a':
            attack(&enemyHP);
            break;
        case 'x':
            return 0;
            break;
        default:
            printf("\nYou skipped your turn.");
        }
        printf("\nENEMY'S TURN");
    }
    if(HP > 0) {
        printf("\n~~VICTORY~~");
    } else {
        printf("\n~~YOU DIED~~");
    }

    return 0;
}
