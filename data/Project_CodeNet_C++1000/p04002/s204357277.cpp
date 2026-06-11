#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 5e5 + 5;
const int logn = log2(maxn) + 1;
const int mod = 1e9 + 7;
map<ii,int> mmap;
int n , h , w;
int res[10];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(fopen(taskname".INP", "r")) {
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    }
    cin >> h >> w >> n;
    for(int i = 0 ; i < n ; ++i){
        int x , y;cin >> x >> y;
        for(int j = -1 ; j <= 1 ; ++j){
            for(int t = -1 ; t <= 1 ; ++t){
                if(x + j > 1 && x + j < h && y + t > 1 && y + t < w){
                    mmap[mp(x + j , y + t)]++;
                }
            }
        }
    }
    for(auto c : mmap){
        res[c.second]++;
    }
    cout << 1ll * (h - 2) * (w - 2) - mmap.size() << '\n';
    for(int i = 1 ; i <= 9 ; ++i)cout << res[i] << endl;
}
