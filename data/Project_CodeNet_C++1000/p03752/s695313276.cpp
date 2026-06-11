#include<bits/stdc++.h>

using ll = long long;
using namespace std;


int main()
{
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    ll ans = 10000000000000000;

    for(int bit = 0; bit < (1 << n); bit++)
    {
        ll sum = 0,count = 0, cur_max = 0;
        //bit := 前よりも高く見せるビルのフラグ
        for(int i = 0; i < n; i++){

            if(bit & (1 << i)){
                sum += max(0LL, cur_max - a[i] + 1);
                count++;
            }else {cur_max = max(cur_max, a[i]);continue;}
            cur_max = max(cur_max, a[i] + max(0LL, cur_max - a[i] + 1));
        }
        if(count < k)continue;
        ans = min(sum, ans);
    }
    cout << ans << endl;
}