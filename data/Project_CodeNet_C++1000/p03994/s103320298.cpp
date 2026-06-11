#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; int K; cin >> S >> K;
    int N=S.size();
    for (int i=0;i<N;++i) if (S[i]!='a'){
        int x=('z'-S[i])+1;
        if (K<x) continue;
        S[i]='a'; K-=x;
    }
    S[N-1]=(char)(((S[N-1]-'a')+K)%26+'a');
    cout << S << '\n';
}