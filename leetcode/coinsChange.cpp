#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int coinChange(int* coins, int coinsSize, int amount) {  
    int table[amount + 1];
    table[0] = 0;
    
    for(int i = 1; i<=amount;i++)
        table[i] = INT_MAX;
    
    for(int i = 1; i<=amount;i++){
        for(int j = 0;j<coinsSize;j++)
            if(coins[j]<=i){
                int sub_res = table[i-coins[j]];
                if(sub_res != INT_MAX && sub_res +1 <table[i])
                    table[i] = sub_res + 1;
            }
    }
    return table[amount] == INT_MAX? -1: table[amount];
}


int main() {
    int* coins;
    const int coinsSize =4;
    int coin[coinsSize]={186,419,83,408};
    coins = coin;
    int amount = 6249;
    int cc = coinChange(coins, coinsSize, amount);
    printf("we need %d coins\n",cc);
}