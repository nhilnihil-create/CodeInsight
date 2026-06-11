#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> a(n+1);
    for (int i=1; i<=n; i++)    cin>>a[i];

    int ans = 0;
    for (int i=1; i<=n; i++)
        if (a[a[i]] == i)
            ans++;

    cout<<ans/2<<endl;
}
