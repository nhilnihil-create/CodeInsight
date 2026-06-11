#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    int H,W;
    cin >> H >> W;
    
    char A[27];
    for(int i=0;i<26;i++){
        A[i] = 'A'+i;
    }
    string S[H+1][W+1];
    for(int i=1;i<=H;i++){
        for(int k=1;k<=W;k++){
            cin >> S[i][k];
            if(S[i][k]=="snuke") cout << A[k-1] << i << endl;
        }
    }
    return 0;
}
