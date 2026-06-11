    #include <bits/stdc++.h>
    using namespace std;
    
    typedef long long ll;
    typedef pair<ll , ll> pair_t;
    
    bool comp(const pair_t &a, const pair_t &b) {
        return a.first < b.first;
    }
    
    ll gcd(ll a, ll b) {
        if(b == 0)
            return a;
        else
            return gcd(b, a % b);
    }
    ll lcm(ll a, ll b) {
        return a / gcd(a, b) * b;
    }

    int main(){
        ll n;
        cin >> n;
        ll t1 , t2;
        t2 = 0;
        for(ll i = 1 ; t2 < n ; i++ ){
            t2 = i * (i + 1) / 2;
            t1 = i;
        }
        //cout << t1 << endl;
        while(n > 0 && t1 > 0){
            if(n >= t1){
                cout << t1 << endl;
                n -= t1;
            }
            t1 -= 1;
        }
        
        return 0;
        
    }