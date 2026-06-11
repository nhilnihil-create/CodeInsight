#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll nCr(ll n,ll r){
    if ( r > n ) return 0;
    if ( r * 2 > n ) r = n - r;
    if ( r == 0 ) return 1;

    ll result = n;
    for (ll i = 2; i <= r; ++i ) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

int main(void){
    ll n,a,b;
    ll sum = 0;

    double avg;
    ll cnt = 0;

    cin >> n >> a >> b;

    vector<ll> v(n,0);
    map<ll, ll> num_cnt;

    for(ll i=0; i<n; i++){
        cin >> v[i];
        num_cnt[v[i]]++;
    }
    
    sort(v.rbegin(), v.rend());

    ll cnt_last = 0;
    for(int i=0; i<a; i++){
        sum += v[i];
    }
    avg = (double)sum / a;

    ll ans = 0;

    int prev_cnt = 0;
    for(int i=0; v[i]>v[a-1]; i++){
        i += num_cnt[v[i]]-1;
        prev_cnt += num_cnt[v[i]];
    }

    if(b-prev_cnt > num_cnt[v[a-1]])
        b = num_cnt[v[a-1]] + prev_cnt;

    if(v[0] != v[a-1])
        b = a;
    
    for(ll i=a-prev_cnt; i<=b-prev_cnt; i++){
        ans += nCr(num_cnt[v[a-1]], i);
        //cout <<  nCr(num_cnt[v[a-1]], i) << ":" << num_cnt[v[a-1]] << "C" << i << endl;
    }

    printf("%lf\n%lld\n", avg, ans);

    return 0;
}