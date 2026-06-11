#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define rrep(i,m, n) for(int i = m; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sum accumulate
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<int>(n,a)));
typedef long long ll;
const int INF = 2000000000;
const long INF64 = 1000000000000000ll;
const ll MOD = 1000000007LL;
typedef unsigned int uint;
int main(){
    int h,w,n;
    std::cin >> h>>w;
    n=h*w;
    std::vector<char> a(h*w);
    rep(i,n)std::cin >> a[i];
    sort(all(a));
    std::vector<int> c;
    int co=1;
    rep(i,n-1){
      if(a[i+1]==a[i])co++;
      else{
        c.pb(co);
        co=1;
      }
    }
    c.pb(co);
    rep(i,c.size()){
      c[i]%=4;
    }
    co=0;
    int ch=0;
    
    rep(i,c.size()){
      co+=c[i]/2;
      ch+=c[i]%2;
    }
    int kyo=(h%2)*(w/2)+(w%2)*(h/2),kyo1=0;
    if(h%2==1&&w%2==1)kyo1++;
    if(co<=kyo&&ch<=kyo1)std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
    
}