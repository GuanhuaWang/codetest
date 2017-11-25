#include <iostream>
int* sortedCoins(int* coins, int coinsSize){
    const int size = coinsSize;
    int temp[size];
    memset(temp,0,size*sizeof(int));
    for(int i =0; i<coinsSize;i++){
        temp[i]= coins[i];
    }
    for(int i = 0; i<size -1; i++){
        for(int j =0;j<size - i -1;j++){
            if(temp[j]>temp[j+1]){
                int t = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = t;
            }
        }
    }
    int* tem = temp;
    return tem;
}


int coinChange(int* coins, int coinsSize, int amount) {
    
    int count = 0;
    int* sorted = sortedCoins(coins, coinsSize);
    
    if (amount == 0)
        return count;
    if (amount < sorted[0])
        return -1;
    
    for(int i =coinsSize-1;i>=0;i--){
        if(amount>=sorted[i]){
            amount-=sorted[i];
            i++;
            count++;
        }
        if(amount == 0)
            return count;
        else if(amount < sorted[0]) {
            printf("amount is %d, sorrted 0 is %d\n", amount,sorted[0]);
            return -2;
        }
    }
    
    return count;
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