#include<cstdio>

int dp[10][10][10][10];
int map[10][10];
int n;

int main(){
    int dfs(int x1, int x2, int y1, int y2);
    scanf("%d", &n);
    int x, y, m;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int q = 0; q <= n; q++){
                for(int k = 0; k <= n; k++){
                    dp[i][j][q][k] = -1;
                }
            }
        }
    }
    while(1){
        scanf("%d%d%d", &x, &y, &m);
        if((x+y+m) == 0){
            break;
        }
        map[x][y] = m;
    }
    printf("%d", dfs(1,1,1,1)+map[1][1]);
    return 0;
}

int dfs(int x1, int y1, int x2, int y2){
    int max(int a, int b);
    if(x1 + x2 + y1 + y2 == 4*n)
        return 0;
    if(dp[x1][y1][x2][y2] != -1)
        return dp[x1][y1][x2][y2];
    int M = 0;
    if(x1 < n && x2 < n)
        M = max(M, dfs(x1+1, y1, x2+1, y2)+map[x2+1][y2]+map[x1+1][y1]*(x1 != x2 || y1 != y2));
    if(x1 < n && y2 < n)
        M = max(M, dfs(x1+1, y1, x2, y2+1)+map[x2][y2+1]+map[x1+1][y1]*(x1+1 != x2 || y1 != y2+1));
    if(y1 < n && x2 < n)
        M = max(M, dfs(x1, y1+1, x2+1, y2)+map[x2+1][y2]+map[x1][y1+1]*(x1 != x2+1 || y1+1 != y2));
    if(y1 < n && y2 < n)
        M = max(M, dfs(x1, y1+1, x2, y2+1)+map[x2][y2+1]+map[x1][y1+1]*(x1 != x2 || y1 != y2));
    dp[x1][y1][x2][y2] = M;
    return M;
}

int max(int a,  int b){
    return a>b?a:b;
}
