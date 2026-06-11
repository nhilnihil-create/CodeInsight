#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int K,T; cin >> K >> T;
    vector<int> a(T);
    int M=0;
    for (int i=0;i<T;++i) cin >> a[i],M=max(M,a[i]);
    cout << max(0,2*M-K-1) << '\n';
}