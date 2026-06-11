#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)cin >> a[i] >> b[i];

    ll nax = 0;

    for(int j = 0; j < n; j++) {
        if((a[j] | k) == k)nax += b[j]; 
    }

    for(int i = 0; i < 30; i++) {
        if(((1<<i)&k)==0)continue;
        //i桁目を潰す
        int lim = k;
        lim ^= (1<<i);
        for(int j = 0; j < i; j++)lim |= (1<<j);
        ll sum = 0;
        for(int j = 0; j < n; j++) {
            if((a[j] | lim) == lim)sum += b[j];
        }
        nax = max(nax, sum);
    }
    cout << nax << endl;
}