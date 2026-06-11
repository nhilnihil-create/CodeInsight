#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll gcd(ll a, ll b){
    if(a < b) return gcd(b, a);
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    ll ret = (a * b)/gcd(a,b);
    return ret;
}

int main(){
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    double mx = 0;
    ll sugar = 0, water = 100 * A;
    for(ll c = 0; c < F+1; c += C){
        for(ll d = 0; d < F+1 - c; d += D){
            ll s = c + d;
            for(ll a = 0; a < F+1; a += A * 100){
                for(ll b = 0; b < F+1 - a; b += B * 100){
                    ll w = a + b;
                    if(s + w > F) continue;
                    if(s > E * (ll)(w/100)) continue;
                    if(s + w == 0) continue;
                    double node = (double)(s) / (double)(w + s);
                    if(node > mx){
                        mx = node;
                        sugar = s;
                        water = w;
                    }
                }
            }
        }
    }
    cout << water + sugar << " " << sugar << endl;

    return 0;
}