#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> a(N);
    for (int i=0;i<N;++i) cin >> a[i],--a[i];
    int ans=0;
    for (int i=0;i<N;++i)
        if (a[a[i]]==i) ++ans;
    cout << ans/2 << '\n';
}