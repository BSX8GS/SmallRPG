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

#ifdef HEAL
void heal() {
    printf("\nYou used heal.");
    if(HP + 20 <= 10){
        HP = HP + 20;
    } else {
        HP = 10;
    }
    printf("\nHP increased to %d.", HP);
}
#endif

#ifdef ENEMYATTACK
void getDemage(int enemyAttack) {
    if(HP - enemyAttack >= 0) {
        HP = HP - enemyAttack;
    } else {
        HP = 0;
    }
    printf("\nYou have %d HP left.", HP);
}
#endif

#ifdef DODGE
int dodge(int random) {
    //dodge with 1:5 chance
    if(2 == random){
        printf("\nYou have dodged the attack of the enemy.");        
        return 0;
    } else {
        return 1;
    }
}
#endif

int main() {
    srand(time(NULL));
    char input;
    //random number between 5 and 8 (inclusive)
    int enemyHP = rand() % 8 + 5;
    int enemyAttack = rand() % 3 + 1;

    printf("Actions:");
    printf("\na = attack the enemy with %d damage", damage);
    printf("\nh = use heal to get 2 HP back");
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
        case 'h':
            heal();
            break;
        case 'x':
            return 0;
            break;
        default:
            printf("\nYou skipped your turn.");
        }
        printf("\nENEMY'S TURN");
        printf("\nEnemy attacks.");
        if(dodge(rand() % 5 + 1) == 1) {
            getDemage(enemyAttack);
        }
    }
    if(HP > 0) {
        printf("\n~~VICTORY~~");
    } else {
        printf("\n~~YOU DIED~~");
    }

    return 0;
}
