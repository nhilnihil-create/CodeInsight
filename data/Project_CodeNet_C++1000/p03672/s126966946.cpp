#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    string S;
    cin >> S;
    int S_size = (int)S.size();
    string S1="";
    string S2="";
    
    rep(i,S_size){
        if(i < S_size/2){
            S1 += S[i];
        }else{
            S2 += S[i];
        }
    }

    while(true){
        string s = S1.substr((int)S1.size() - 1, 1);
        S1 = S1.erase((int)S1.size() - 1);
        S2 = s + S2;
        S2 = S2.erase((int)S2.size() - 2);
        if(S1 == S2){
            int ans = 2*(int)S1.size();
            cout << ans << endl;
            break;
        }
    }

    return 0;
}