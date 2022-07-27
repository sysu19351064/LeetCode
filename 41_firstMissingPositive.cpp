#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int num1 = 1;
        int pre = 1;
        bool flag = false;
        while(!flag){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] >=0 && num1 >= nums[i])
                    num1 = max({nums[i]+1, num1});
            }
            if(pre != num1){
                pre = num1;
            }
            else{
                flag = true;
            }
        }
        return num1;
//        int num2 = 1;
//        for(int i = int(nums.size()-1); i >= 0; i--){
//            if(nums[i] >=0 && num2 >= nums[i])
//                num2 = max({nums[i]+1, num2});
//        }
//        return max({num1, num2});

    }
};

int main(){
    vector<int>nums = {1,2,6,3,5,4};
    class Solution solution;
    cout << solution.firstMissingPositive(nums) << endl;
    return 0;
}
