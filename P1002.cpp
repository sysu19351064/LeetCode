#include<cstdio>

long long dp[21][21] = {1};
bool mark[21][21];
const int Const[2][9] = {{0, -2, -1, 1, 2, 2, 1, -1, -2}, {0, 1, 2, 2, 1, -1, -2, -2, -1}};

int main(){
    int t[2];
    int h[2];
    scanf("%d%d%d%d", t, t+1, h, h+1);
    for(int i = 0; i < 9; ++i){
        if(h[0] + Const[0][i] >= 0 && h[0] + Const[0][i] <= t[0] && h[1] + Const[1][i] >= 0 && h[1] + Const[1][i] <= t[1]){
            mark[h[0]+Const[0][i]][h[1]+Const[1][i]] = 1;
        }
    }
    for(int x = 0; x <= t[0]; ++x){
        for(int y = 0; y <= t[1]; ++y){
            if(x){
                dp[x][y] += dp[x-1][y];
            }
            if(y){
                dp[x][y] += dp[x][y-1];
            }
            dp[x][y] *= !mark[x][y];
        }
    }
    printf("%lld", dp[t[0]][t[1]]);
    return 0;
}
