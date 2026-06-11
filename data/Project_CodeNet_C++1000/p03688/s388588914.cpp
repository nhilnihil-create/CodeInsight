#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    sort(all(a));
    if(a.back() - a.front() > 1){
        cout << "No" << endl;
    }else if(a.back() == a.front()){
        ll k = a.back();
        ll mmin = 1;
        ll mmax;
        if(n%2) mmax = (n-1)/2;
        else mmax = n/2;
        if((mmin <= k && k <= mmax) || k == n-1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        ll k = a.back();
        ll tmp = 0;
        for(i = 0;i < n;++i){
            if(a.at(i) == k) ++tmp;
        }
        ll mmin = 1;
        ll mmax;
        if(tmp%2) mmax = (tmp-1)/2;
        else mmax = tmp/2;
        if(mmin <= k-1 - (n - tmp - 1) && k-1 - (n - tmp - 1) <= mmax){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}