class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int max_cost=0;
        for(int cost :  costs){
            max_cost = max(max_cost, cost);
        }

        vector<int> freq(max_cost + 1, 0);
        for(int cost : costs)
        {
            freq[cost]++;
        } 

        int iceCreamCount = 0;

        for(int price= 1; price<= max_cost; ++price){
            if(freq[price] ==0) continue;

            if (coins >= (long long)price * freq[price]){

                coins -= price * freq[price];
                
                iceCreamCount += freq[price];
            }

            else{
                int affordable = coins/price;
                iceCreamCount += affordable;
                break;

            }
        }
        return iceCreamCount;
    }
};