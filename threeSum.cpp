#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int re = 214875-target;
        int min_num = 214875;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            int l1 = i+1;
            int l2 = nums.size()-1;
            while(l2 > l1){
                int total = nums[i] + nums[l1] + nums[l2];
//                cout << nums[i] << ' ' << nums[l1] << ' ' << nums[l2] << ' ' <<endl;
                if(total < target){
                    if(abso(total, target) < min_num){
                        min_num = abso(total, target);
                        re = total;
//                        cout << "re " << re <<endl;
                    }
                    l1++;
                }
                else if(total > target){
                    if(abso(total, target) < min_num){
                        min_num = abso(total, target);
                        re = total;
//                        cout << "re " << re <<endl;
                    }
                    l2--;
                }
                else{
                    return target;
                }
            }
        }
        return re;
    }

    int abso(int a, int b){
        if(a > b){
            return a-b;
        }
        else{
            return b-a;
        }
    }
};


//int main(){
//     vector<int> nums = {1,1,1,0};
//    int target = -100;
//    class Solution solution;
//    cout << solution.threeSumClosest(nums, target) << endl;
//}
