/*只能过一部分，因为涉及到高精度的计算，还不会*/

#include<cstdio>
#define bll __int128

int m, n;
int map[80][80];
long long max[80];
bll sum = 0;

int main(){
    long long Max(long long, long long);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", map[i]+j);
        }
        long long dp[80][80];
        for(int j = m-1; j >= 0; j--){
            for(int k = j; k < m; k++){
                if(k ==  j){
                    dp[j][k] = 2*map[i][j];
                }
                else{
                    dp[j][k] = 2*Max(dp[j+1][k]+map[i][j], dp[j][k-1]+map[i][k]);
                }
            }
        }
        sum += dp[0][m-1];
    }
    printf("%lld", sum);
    return 0;
}


long long Max(long long a, long long b){
    return a>b?a:b;
}
