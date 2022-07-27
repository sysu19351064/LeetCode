#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    map<int, int> choose;
    vector<vector<int>> res;
    int n  = 0;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(auto num : nums){
            choose[num]++;
            n++;
        }
        vector<int> path;
        back_track(path, choose);
        return res;
    }

    void back_track(vector<int>& path, map<int, int>& choose_){
        if(path.size() == n){
            res.push_back(path);
            return;
        }
        for(auto m : choose_){
            if(m.second > 0){
                path.push_back(m.first);
                choose_[m.first]--;
                back_track(path, choose_);
                path.pop_back();
                choose_[m.first]++;
            }
        }
    }

};


int main(){
    vector<int> nums = {1, 1, 2, 2, 3};
    class Solution solution;
    for(auto const& vec : solution.permuteUnique(nums)){
        for(auto c : vec){
            cout << c << ' ';
        }
        cout << endl;
    }
    return 0;
}
