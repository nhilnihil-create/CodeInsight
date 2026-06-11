#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>

#define reps(i,f,n) for(ll i=f; i<ll(n); ++i)
#define rep(i,n) reps(i,0,n)

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;

const char* color = "RYGB";

signed main()
{
    int h, w, d;
    cin >> h >> w >> d;
    
    if(d%2 == 1){
        rep(i, h){
            rep(j, w) cout << color[(i+j)%4];
            cout << endl;
        }
    }
    else{
        vector<string> S(h, string(w, ' '));
        
        rep(i, h) rep(j, w){
            S[i][j] = color[(((i + j) / d) % 2) * 2 + (((i - j + w*10 + h*10) / d) % 2)];
        }
        
        /*
        for(int k=0; k<h+w-1; k+=2){
            rep(j, w){
                int i = k - j;
                if(i < 0 || h <= i) continue;
                S[i][j] = color[((k / d) % 2) * 2 + (((j + k/2) / (d/2)) % 2)];
            }
        }
        */
        
        rep(i, h){
            cout << S[i] << endl;
        }
    }
}
