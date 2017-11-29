int maxProfit(int* prices, int pricesSize) {
    int* leftprofit;
    leftprofit = malloc(pricesSize * sizeof(int*));
    #memset(leftprofit, 0, pricesSize*sizeof(int));

    if(pricesSize<=1) return 0;
    
    leftprofit[0] = 0;
    
    int minprice = prices[0], maxprofit = 0;
    
//max profit from price 0 to i;    
    for(int i = 1; i< pricesSize; i++){
        minprice = (minprice< prices[i])? minprice: prices[i];
        maxprofit = (maxprofit>(prices[i]-minprice))?maxprofit:(prices[i]-minprice);
        leftprofit[i] = maxprofit;
    }
    
//max profit from i+1 .. pricesSize;
    int maxprice = prices[pricesSize - 1];
    int res = leftprofit[pricesSize - 1];
    int rightMaxProfit = 0;
    maxprofit = 0;
    for(int i = pricesSize-2; i>=0;i--){
        if(prices[i]>maxprice)
            maxprice = prices[i];
        else
            rightMaxProfit = (rightMaxProfit>(maxprice - prices[i])?rightMaxProfit:maxprice - prices[i]);
        
        res = (res>rightMaxProfit + leftprofit[i])? res: rightMaxProfit + leftprofit[i];
    }
    
    return res;
}