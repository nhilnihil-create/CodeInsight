#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair

void solve(int H,int W,int h,int w) {
    int u = 501;
    int neg = (h*w-1)*u+1;
    vvi a(H, vi(W, u));
    for (int i=h-1; i<H; i+=h) {
        for (int j=w-1; j<W; j+=w) {
            a[i][j] = -neg;
        }
    }
    int sum = 0;
    rep(i,H) rep(j,W) sum += a[i][j];
    if (sum > 0) {
        cout << "Yes" << endl;
        rep(i,H) {
            rep(j,W) {
                if (j > 0) cout << " ";
                cout << a[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "No" << endl;
    }
}

int main() {
    int H,W,h,w; scanf("%d%d%d%d", &H,&W,&h,&w);
    solve(H,W,h,w);
    return 0;
}
