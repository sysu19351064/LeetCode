#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        while(!matrix.empty()){
            res.insert(res.end(), matrix[0].begin(), matrix[0].end());
            matrix.erase(matrix.begin());
            if(matrix.empty()){
                break;
            }
            int right = matrix[0].size()-1;
            int down = int(matrix.size()-1);
            for(int i = 0; i <= down; i++){
                res.push_back(matrix[i][right]);
            }
            for(int i = down; i >= 0; i--){
                matrix[i].erase(matrix[i].end()-1);
                if(matrix[i].empty()){
                    matrix.erase(matrix.begin()+i);
                }
            }
            if(matrix.empty()){
                break;
            }
            right = int(matrix[0].size()-1);
            for(int i = right; i >= 0; i--){
                res.push_back(matrix[down][i]);
            }
            matrix.pop_back();
            if(matrix.empty()){
                break;
            }
            down = int(matrix.size()-1);
            for(int i = down; i >= 0; i--){
                res.push_back(matrix[i][0]);
//                matrix[i].erase(matrix[i].begin());
            }
            for(int i = down; i >= 0; i--){
                matrix[i].erase(matrix[i].begin());
                if(matrix[i].empty()){
                    matrix.erase(matrix.begin()+i);
                }
            }
        }
        return res;
    }
};

int main(){
//    vector<vector<int>> matrix = {{1,2,3}, {4,5,6},{7,8,9}};
//    vector<vector<int>> matrix = {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}};
    vector<vector<int>> matrix = {{1, 2, 3}};
    class Solution solution;
    for(auto i : solution.spiralOrder(matrix)){
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
