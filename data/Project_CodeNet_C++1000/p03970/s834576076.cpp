#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S,T="CODEFESTIVAL2016"; cin >> S;
    int ans=0;
    for (int i=0;i<S.size();++i)
        if (S[i]!=T[i]) ++ans;
    cout << ans << '\n';
}