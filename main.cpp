#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int k = 0;
        int m = 0;
        int n = nums.size();
        while(l < r){
            cout << "l: " << l << ' ' << "r: " << r << endl;
            // left <= target <= right，无旋转，正常二分。
            if(nums[l] < nums[r]){
                // k = 0;
                m = (l + r)/2 ;
                if(nums[m] > target)
                    r = m;
                else
                    l = m+1;
            }
            else{
                // right < left <= target，有旋转，right缩减。
                if(nums[l] <= target){
                    r--;
                    k = n-r;
                }
                // target <= right < left，有旋转，left缩进。
                else if(nums[r] >= target){
                    l++;
                    k = n - l;
                }
                else
                    return -1;
            }
        }
        cout << 'l' << l << endl;
        if(nums[l] == target){
            return l % n;
        }
        else return -1;
    }
};


int main() {
    class Solution solution;
    vector<int> nums = {1, 3};
    int target = 2;
    cout << solution.search(nums, target) << endl;
}
