#include <iostream>
#include <vector>
#include <map>
using namespace std;


vector<vector<char>> res(9, vector<char>(9, '.'));
class Solution {
public:
    vector<char> element = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    void solveSudoku(vector<vector<char>>& board) {
        back_track(board);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                board[i][j] = res[i][j];
            }
        }
        cout << "done" << endl;
    }


    void back_track(vector<vector<char>>& board){
//        cout << "judge" << endl;
        // 判断是否填充完毕
        bool flag = true;
        int i, j;
        for(i = 0; i < 9; i++){
            if(!flag) {
//                i--;
                break;
            }
            for(j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    flag = false;
                    cout << "i: " << i << " j: " << j <<endl;
                    i--;
                    break;
                }
            }
        }

        if(flag){
            cout << "YES!!!!!!!!!!!!!" << endl;
            for(int m = 0; m < 9; m++){
                for(int n = 0; n < 9; n++){
                    res[m][n] = board[m][n];
                }
            }
            return ;
        }
        cout << "i: " << i << " j: " << j << endl;
        // 根据位置i, j来进行回溯
        // 确定选择列表
//        map<char, int> choose;
        int* choose = (int*)malloc(sizeof(int) * 9);
        for(int m = 0; m < 9; m++){
            choose[m] = 0;
        }
        for(int m = 0; m < 9; m++){
            // cout << board[i][m] << ' ' <<board[m][j] << endl;
            if(board[i][m] != '.'){
                choose[board[i][m]-49]++;
            }
            if(board[m][j] != '.'){
                choose[board[m][j]-49]++;
            }
        }
//        cout << i/3  << ' ' << j/3 << endl;
        for(int m = (i/3)*3; m < (i/3 + 1)*3; m++){
            for(int n = (j/3)*3; n < (j/3 + 1)*3; n++){
                // cout << "m: " << m << " n: " << n << endl;
                if(board[m][n] != '.'){
                    choose[board[m][n]-49]++;
                }
            }
        }
        cout << "choose: ";
        for(int q = 0; q < 9; q++){
            if(choose[q] == 0){
                cout << char(q+49) << ' ';
            }
        }
        cout << endl;
        // 根据选择列表进行递归
        for(int q = 0; q < 9; q++){
            if(choose[q] == 0){
                board[i][j] = char(q+49);
                cout << "i: " << i << " j: " << j << "  back_track: " << char(q+49) << endl;
                back_track(board);
                board[i][j] = '.';
            }
        }
        free(choose);
    }
};

int main() {
    vector<vector<char>> board;
    board.push_back({'.', '.', '7', '1', '.', '.', '.', '3', '.'});
    board.push_back({'1', '.', '.', '.', '.', '4', '.', '6', '5'});
    board.push_back({'9', '.', '.', '.', '.', '.', '.', '.', '.'});
    board.push_back({'6', '4', '.', '7', '1', '.', '.', '.', '.'});
    board.push_back({'.', '5', '.', '.', '.', '.', '7', '.', '.'});
    board.push_back({'3', '.', '8', '.', '5', '.', '.', '.', '.'});
    board.push_back({'.', '.', '.', '3', '.', '.', '.', '.', '2'});
    board.push_back({'.', '.', '.', '.', '.', '.', '.', '4', '.'});
    board.push_back({'.', '.', '.', '.', '2', '6', '.', '9', '1'});
    class Solution solution;
    solution.solveSudoku(board);
    return 0;
}
