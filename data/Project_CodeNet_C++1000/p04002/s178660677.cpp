#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cstring>
#include<cmath>
#include <numeric>
#include<queue>
#include<climits>
#include<cstdio>
#include<map>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
//#define INF ((LLONG_MAX) / (2))
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
typedef pair<ll,int> LL_IP;
typedef pair<ll,ll> LL_LLP;
#define INF 1000000007
#define MAX_H 100005

int main(){

    ll h,w,n,x,y;
    cin >> h >> w >> n;
    vector<P> arr;
    REP(i,n){

        cin >> x >> y;
        x--;
        y--;
        for(ll j = 0;j <= 2;j++){
            for(ll k = 0;k <= 2;k++){
                ll nx = x-j;
                ll ny = y-k;
                if(nx >= 0 && nx+2 < h && ny >= 0 && ny+2 < w){
                    arr.push_back(make_pair(nx,ny));
                }
            }
        }
    }
    /*正方形としてありうるものの左上の頂点を列挙*/

    map<P,ll> mp;
    map<P,ll>::iterator itr;
    ll black = 0;

    REP(i,arr.size()){
        mp[arr[i]]++;
    }

    vector<ll> ans(10,0);
    for(itr = mp.begin();itr != mp.end();itr++){
        ans[itr->second]++;
        black++;
    }
    ans[0] = (h-2)*(w-2) - black;
    REP(i,10){
        cout << ans[i] << endl;
    }

return 0;
}        