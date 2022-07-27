#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:

    vector<vector<int>> res;
    map<int, int> choice;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for(auto i : candidates){
            choice[i]++;
        }
        vector<int> path;
        back_track(path, 0, 0, target);
        return res;
    }

    void back_track(vector<int>& path, int num, int sum, int target){
        if(sum > target){
            return;
        }
        if(sum == target){
            res.push_back(path);
            return;
        }
        if(num == choice.size())
            return;
        while(choice[num] == 0 && num <= 50){
            num++;
        }
        // 选择这个元素，考虑是否有多个？
        for(int i = 0; i <= choice[num]; i++){
            path.insert(path.end(), i, num);
            back_track(path, num+1, sum+num*i, target);
            for(int j = 0; j < i; j++){
                path.pop_back();
            }
        }
    }
};

int main(){
    vector<int>candidates = {10,1,2,7,6,1,5};
    int target = 8;
    class Solution solution;
    for(auto vec : solution.combinationSum(candidates, target)){
        for(auto c : vec){
            cout << c << ' ';
        }
        cout << endl;
    }
    return 0;
}

