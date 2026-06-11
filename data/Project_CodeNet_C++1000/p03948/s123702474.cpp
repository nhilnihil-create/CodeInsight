#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <tuple>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <iterator>
#include <array>
#include <memory>
#include <stack>
using ll = long long;
//#define int ll
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
#define MAX 9999999
using namespace std;
typedef pair<int, int> pii;
typedef pair<double,double>pdd;
signed main(){
    int n,t; cin>>n>>t;
    vector<int>v(n);
    rep(i,n){
        cin>>v[i];
    }
    map<int,int>mp;
    int mini=INF;
    rep(i,n){
        if(!i){cmin(mini,v[i]);continue;}
        if(mini>v[i]){
            cmin(mini, v[i]);
            continue;
        }
        mp[v[i]-mini]++;
    }
    int ans=0;
    int maxi=0;
    for(auto itr:mp){
        if(maxi<itr.first)ans=itr.second;
    }
    cout<<ans<<endl;
}
