#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int n = 0;
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        n = int(matrix.size());
        // 找到每一个轮
        for(int i = 0; i < n/2; i++){
            // 第一行的元素逐个变换
            for(int j = i; j < n-i-1; j++){
                int cur[2] = {i, j};
                // 不回到起点时
                int temp_cur = matrix[cur[0]][cur[1]];;
                int temp_next;
                int count = 4;
                while(count--){
                    //next先被覆盖，先保存next的值
                    change(cur, i, n-1-2*i);
                    temp_next = matrix[cur[0]][cur[1]];
                    matrix[cur[0]][cur[1]] = temp_cur;
                    temp_cur = temp_next;
                }
                //matrix[next[0]][next[1]] = temp_cur;
            }
        }
    }

    void change(int* cur, int i, int n) const{
        if(cur[0] == i && cur[1] < i+n){
            cur[0] = cur[1];
            cur[1] = i+n;
        }
        else if(cur[1] == i+n && cur[0] < i+n){
            cur[1] = n-cur[0]+2*i;
            cur[0] = i+n;
        }
        else if(cur[0] == i+n && cur[1] > i){
            cur[0] = cur[1];
            cur[1] = i;
        }
        else if(cur[1] == i && cur[0] > i){
            cur[1] = n-cur[0]+2*i;
            cur[0] = i;
        }
    }
};


int main(){
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    class Solution solution;
    solution.rotate(matrix);
    for(auto vec : matrix){
        for(auto num : vec){
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}

