int maxProfit(int* prices, int pricesSize) {
    int rev = 0;
    for(int i = 1; i<pricesSize;i++){
        rev += prices[i] > prices[i-1] ? prices[i] - prices[i-1]:0;
    }
    return rev;
}