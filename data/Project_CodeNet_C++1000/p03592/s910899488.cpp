#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M,K,ok=0; cin >> N >> M >> K;
    for (int i=0;i<=N;++i)
        for (int j=0;j<=M;++j)
            if (i*j+(N-i)*(M-j)==K) ok=1;
    cout << (ok?"Yes":"No") << '\n';
}