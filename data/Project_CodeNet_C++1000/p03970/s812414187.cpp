#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
int main() {
    string S;
    cin >> S;
    string ref = "CODEFESTIVAL2016";
    int ans;
    REP(i,S.length()){
        if(S[i] != ref[i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}