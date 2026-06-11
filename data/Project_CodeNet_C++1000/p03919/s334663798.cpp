#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1e9;
int MOD = 1e9+7;
main(){
    int H,W;
    string S;
    cin >> H >> W;
    for(int i = 1;i <= H;i++){
        for(int j = 0;j < W;j++){
            cin >> S;
            if(S == "snuke"){
                printf("%c%d\n",'A'+j,i);
            }
        }
    }
}