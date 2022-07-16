//best time to buy and sell stock
//url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//APPROACH: GIVEN A CONDITION, WE CANNOT SELL BEFORE WE BUY, MEANING MINIMUM STOCK VALUE SHOULD BE BEFORE MAXIMUM STOCK VALUE IN THE ARRAY
//WE TRAVERSE THE ARRAY --> AT EVERY ITERATION WE FIND THE MINMIMUM VALUE TILL THAT POINT AND TRY TO FIND THE MAXIMUM PROFIT TILL THAT POINT
// HERE THE MAXIMUM VALUE IS DEPENDENT ON MINIMUM VALUE (I.E MAX SHOULD BE AFTER MIN) AND THERE CANNOT BE FIXED MINIMUM POINT, I.E IT WILL ALSO CHANGE
// SO WE ONLY TRY TO FIND THE MINMUM AND CALCULATE THE MAX PROFIT AND DO NOT CARE TO FIND THE MAXIMUM VALUE OF THE STOCK AS IT IS BEING TAKEN CARE OF AUTOMATICALLY


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price=INT_MAX,profit=0;
        for(int i=0;i<prices.size();i++){
            //finding the minimum value of stock to buy
            buy_price = min(buy_price,prices[i]);
            //calculating the maximum profit
            profit = max(profit,(prices[i]-buy_price));
        }
        return profit; 
    }
};


//T.C: O(N)
//S.C: O(1)
