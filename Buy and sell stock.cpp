// best time to buy and sell stock provided, one needs to buy before sell and calculate the maximum profit
//URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//APPROACH: find the minimum price and calculate the profit by subtracting the current price and the minimum buy price.


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

//T.C : O(N)
//S.C : O(1)
