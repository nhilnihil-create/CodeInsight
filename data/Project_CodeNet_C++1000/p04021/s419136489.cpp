#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<pair<int, int>> v(n);
    for (int i=0; i<n; i++) {
        cin>>v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    for (int i=0; i<n; i++)
        if (i%2 != v[i].second%2)
            ans++;

    cout<<ans/2<<endl;
}
