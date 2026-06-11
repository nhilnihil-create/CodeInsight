#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

signed main(){
    char c;
    cout << "? " << 10'000'000'000LL << endl;
    cin >> c;
    if(c == 'Y'){
        for(ll i=1'000'000'000; i>=1; i/=10){
            cout << "? " << i+1 << endl;
            cin >> c;
            if(c == 'N'){
                cout << "! " << i*10 << endl;
                return 0;
            }
        }
        cout << "! 1" << endl;
        return 0;
    }

    for(ll i=1'000'000'000; i>=1; i/=10){
        cout << "? " << i << endl;
        cin >> c;
        if(c == 'Y'){
            ll r = i*10;
            ll l = i;
            while(r-l > 1){
                ll m = (r+l)/2;
                cout << "? " << m << 0 << endl;
                cin >> c;
                if(c == 'Y') r = m;
                else l = m;
            }
            cout << "! " << r << endl;
            break;
        }
    }
}