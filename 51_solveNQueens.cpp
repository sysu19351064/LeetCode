#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N = 9;
int col[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
int line1[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int line2[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> path;
        back_track(path);
        return res;
    }

    void back_track(vector<string>& path){
        int m = int(path.size());
        if(m == N){
            res.push_back(path);
            return;
        }
        m--;
        string choice(N, 'Q');
        string ss(N, '.');
        for(int i = 0; i < N; i++){
            if(col[i] == -1 && line1[N+m-i] == -1 && line2[m+i] == -1) {
                ss[i] = 'Q';
                path.push_back(ss);
                col[i] = line1[N+m-i] = line2[m+i] = m;
                back_track(path);
                path.pop_back();
                ss[i] = '.';
                col[i] = line1[N+m-i] = line2[m+i] = -1;
            }
        }
    }
};


int main(){
    int n = 9;
    class Solution solution;
//    cout << solution.solveNQueens(n).size() << endl;
    for(const auto& vec : solution.solveNQueens(n)){
        for( const auto& s : vec){
            cout << s << endl;
        }
        cout << endl;
    }

    return 0;
}

