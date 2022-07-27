#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        if(n == 0) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int l = 0;
        int r = n - 1;
        int m;
        while (nums[l] < nums[r]) {
            m = (l + r)/2;
            if (nums[m] < target){
                l = m + 1;
            }
            else if(nums[m] > target)
                r = m - 1;
            else{
                if(nums[l] != target)
                    l++;
                if(nums[r] != target)
                    r--;
            }
        }
        if(nums[l] == target){
            res.push_back(l);
            res.push_back(r);
        }
        else{
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
};

int main() {
    class Solution solution;
    vector<int> nums = {6};
    int target = 6;
    vector<int> res(solution.searchRange(nums, target));
    cout << res[0] << ' ' << res[1] << endl;
    return 0;
}

