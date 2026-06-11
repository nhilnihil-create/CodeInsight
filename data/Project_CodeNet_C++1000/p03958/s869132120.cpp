#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<cassert>
#include<climits>
#include<string>
#include<bitset>
#include<cfloat>
#include<unordered_set>
#include<iomanip>
#include<numeric>

using namespace std;
using ll =  long long;
using pint =  pair<int,int>;
using vint = vector<int>;
using vvint = vector<vint>;
using vpint = vector<pint>;
#define repi(i,start,end) for(int (i)=(start),TemPNuM=(int)(end);(i)<TemPNuM;++(i))
#define rep(i,end) repi((i),0,(end))
#define rfor(x,v) for(auto& (x) : (v))
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fsort(v,lambda) sort(all((v)),(lambda))
#define vin(v) rep(i,(v).size())cin >> (v)[i];
#define vpin(v) rep(i,(v).size())cin>>v[i].first>>v[i].second
//#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>void println(T a){if(cout.precision()!=12)cout<<setprecision(12);cout<<a<<endl;}
//lambda: [](int x, int y){return x<y;}

signed main(void){
    int k, t; cin >> k >> t;
    vint a(t); vin(a);
    sort(rall(a));
    cout << max(a[0] - 1 - (k - a[0]), 0) << endl;

    return 0;
}
