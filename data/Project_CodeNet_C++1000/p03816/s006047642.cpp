#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    ll a[n];
    map<ll, int> m;
    ll cou = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        auto itr = m.find(a[i]);
        if(itr == m.end()){
            m.insert(make_pair(a[i], 1));
        }else{
            m[a[i]]++;
            cou++;
        }
    }

    if(cou == 0){
        cout << n << endl;
    }else{
        ll k = cou / 2;
        if(cou % 2 != 0){
            k++;
        }

        cout << n - (k * 2) << endl;
    }
}