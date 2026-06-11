#include <bits/stdc++.h>
#define int long long
using namespace std;
int dx[3][8] = {{2,2,2,1,1,1,0,0},{1,1,1,-1,-1,-1,0,0},{-2,-2,-2,-1,-1,-1,0,0}};
int dy[3][8] = {{0,1,2,0,1,2,1,2},{1,0,-1,1,0,-1,1,-1},{-2,-1,0,-2,-1,0,-2,-1}};
main(){
    int h,w,n;
    scanf("%lld%lld%lld",&h,&w,&n);
    int ct[10]; memset(ct,0,sizeof(ct));
    ct[0] = (h-2)*(w-2);
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        x--; y--;
        for (int p = 0; p < 9; p++){
            int row = p/3;
            int column = p%3;
            int r = 0;
            bool valid = true;
            for (int k = 0; k < 8; k++){
                int nx = x + dx[row][k], ny = y+ dy[column][k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w){
                    r += m[nx*w+ny];
                }
                else{
                    valid = false;
                    break;
                }
            }
            if (valid){
                //printf("valid %lld\n",r);
                ct[r]--;
                ct[r+1]++;
            }
        }
        m[x*w+y] = 1;
    }
    for (int i = 0; i < 10; i++){
        printf("%lld\n",ct[i]);
    }
}
