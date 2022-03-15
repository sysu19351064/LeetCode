#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> re;
        if(nums.size() < 3){
            return re;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++){
//            cout << "i:" << i << ' ';
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1; j < nums.size()-1; j++){
//                cout << "j:" << j << ' ';
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int l1 = j+1;
                int l2 = nums.size()-1;
                while(l1 < l2){
//                    cout << "l1:" << l1 << ' ' << "l2:" << l2;
                    long total = nums[i] + nums[j] + nums[l1] + nums[l2];

                    if(total < target){
//                        cout << "small" <<endl;
                        l1++;
                    }
                    else if(total > target){
//                        cout << "big" <<endl;
                        l2--;
                    }
                    else{
//                        cout << "equal" <<endl;
                        vector<int> temp = {nums[i], nums[j], nums[l1], nums[l2]};
                        re.push_back(temp);
                        l1++;
                        l2--;
                        while(nums[l1] == nums[l1-1] && l1 < l2){
                            l1++;
                        }
                        while(nums[l2] == nums[l2+1] && l1 < l2){
                            l2--;
                        }

                    }
                }

            }
        }
        return re;
    }
};


int main(){
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    int target = 0;
//    vector<int> nums = {1,0,-1,0,-2,2};
//    int target = 0;
    class Solution solution;
    for(auto vec : solution.fourSum(nums, target)){
        for(auto num : vec){
            cout << num << ' ';
        }
        cout << endl;
    }
}
