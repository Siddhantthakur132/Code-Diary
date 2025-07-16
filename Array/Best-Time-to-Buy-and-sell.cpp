/*
Approach:
- We want to maximize profit by buying at the lowest price and selling at a higher price later.
- Initialize `bestbuy` with the first day's price (minimum so far).
- Traverse the price list from the second day:
    - If the current price is greater than `bestbuy`, calculate profit and update `maxp` if it's higher.
    - Always update `bestbuy` to the minimum value seen so far to ensure we get the lowest buying price.
- Finally, return the maximum profit that could be made.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0;
        int bestbuy = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(bestbuy < prices[i]) {
                maxp = max(maxp, prices[i] - bestbuy);
            }
            bestbuy = min(bestbuy, prices[i]);
        }
        return maxp;
    }
};
