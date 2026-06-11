// g++ macro.cpp -std=c++14
#include <bits/stdc++.h> //STL include
typedef long long ll;// long long int
const ll INF = 10000000000;//INFinity
using namespace std;//namespace

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}//transform
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//#define int long long // yabai

#define dump(x)  cout << #x << " = " << (x) << endl;// debug cout

#define FOR(i,a,b) for(int i=(a);i<(b);++i)// for macro
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)

#define ALL(obj) (obj).begin(),(obj).end()// iterator

#define pb(a) push_back(a)//push_back
#define mp make_pair// make_pair


int main(){

    int h,w,n;
    cin>>h>>w>>n;

    vector<int>a(n);
    vector<int>b(n);
    REP(i,n)cin>>a[i]>>b[i];
    map<pair<int,int>,ll> map_;

    REP(i,n)REP(j,3)REP(k,3)if(a[i]-2+j>=0&&a[i]-2+j<h&&b[i]-2+k>=0&&b[i]-2+k<w)map_[mp(a[i]-2+j,b[i]-2+k)]++;

    vector<ll> ans(10,0);
    for(auto t:map_)if(t.first.first!=0&&t.first.second!=0&&t.first.first!=h-1&&t.first.second!=w-1)ans[t.second]++;
    ans[0]=1LL*(h-2)*(w-2)-accumulate(ALL(ans),0LL);
    for(auto a:ans)cout<<a<<endl;




    return 0;
}
