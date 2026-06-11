#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, ind;
    ll l;
    cin >> n >> l;
    bool res = false;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        if(a[i] + a[i + 1] >= l)res = true,ind = i;
    }
    if(!res) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    vector<int> va = {ind};
    for(int i = ind + 1; i < n - 1; i++)va.emplace_back(i);
    for(int i = ind - 1; i >= 0; i--)va.emplace_back(i);
    reverse(va.begin(), va.end());
    for(auto i : va)cout << i + 1 << endl;

}