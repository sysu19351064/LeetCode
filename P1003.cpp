#include<cstdio>

int arr[10000][4];

int main(){
    int res = -1;
    int n, a, b, g, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d%d", arr[i], arr[i]+1, arr[i]+2, arr[i]+3);
    }
    int x,  y;
    scanf("%d%d", &x, &y);
    for(int i = 0; i < n; i++){
        if(x >= arr[i][0] && x < arr[i][0]+arr[i][2] && y >= arr[i][1] && y < arr[i][1]+arr[i][3])
            res = i+1;
    }
    printf("%d", res);
    return 0;
}

