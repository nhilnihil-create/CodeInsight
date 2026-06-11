#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

template<class V, int ME> class BIT{
    public:
        V bit[1<<ME];
        V operator()(int e){V s=0;e++;while(e) s+=bit[e-1],e-=e&-e;return s;}
        V add(int e,V v){e++;while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};

BIT<ll,20> bt;
int N, M;
vector<int> E[100009];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>M;
    rep(i,N){
        int x,y; cin>>x>>y;
        E[y-x+1].push_back(x);
    }
    
    int morethan=N;
    rep1(i,M){
        int ret=0;
        for(int x=i;x<=M;x+=i) ret+=bt(x);
        
        for(auto& e:E[i]) bt.add(e,1), bt.add(e+i,-1);
        cout1(morethan+ret);
        morethan-=E[i].size();
    }
}