#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return true;
        }
        int dp[30000] = {0};
        int i = 0;
        int max = 0;
        while(dp[i] < n-nums[dp[i]]-1 && i < n){
            if(nums[dp[i]] == 0)
                return false;
            for(int j = 0; j <= nums[dp[i]]; j++){
                if(max < j + nums[j+dp[i]]){
                    max = j + nums[j+dp[i]];
                }
            }
            dp[i+1] += max;
            i++;
        }
        return dp[i] + nums[dp[i]] + 1 >= nums.size();
    }
};


int main(){
    vector<int> nums = {1, 3, 2};
    class Solution solution;
    cout << solution.canJump(nums) << endl;
    return 0;
}

