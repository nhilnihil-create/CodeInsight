#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double PI = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

int main(){
    int H,W;
    cin >> H >> W;
    int N;
    cin >> N;
    int a[N+1];
    for(int i = 1; i < N+1; i++) cin >> a[i];
    int ans[H][W];
    int x = 0, y = 0,v = 1;
    for(int i = 1; i < N+1; i++){
        while(a[i] > 0){
            ans[x][y] = i;
            a[i]--;
            if(v == 1) y++;
            else y--;
            if(y >= W){
                y = W-1;
                x++;
                v = 0;
            }
            else if(y < 0){
                y = 0;
                x++;
                v = 1;
            }
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
