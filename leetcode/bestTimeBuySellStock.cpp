int maxProfit(int* prices, int pricesSize) {
    if(pricesSize<=1)
        return 0;
    
    int minP = prices[0];
    int profit = prices[1] - prices[0];
    
    for(int i = 2; i < pricesSize;i++){
        minP = (prices[i-1]<minP)? prices[i-1]: minP;
        profit = (profit>prices[i] - minP)? profit: prices[i]-minP;
    }
    
    if(profit < 0){
        return 0;
    }
    
    return profit;
}