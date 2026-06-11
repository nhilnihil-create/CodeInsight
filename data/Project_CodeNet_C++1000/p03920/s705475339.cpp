#include<bits/stdc++.h>
#define rep(i,n) for(size_t i=0;i<(size_t)(n);i++)
#define rrep(i,n) for(size_t i=(size_t)(n)-1;i>=0;i--)
#define each(a,x) for(auto a : (x))
#define all(a) (a).begin(),(a).end()
#define chmin(a,b) ((a) = min((a),(b)))
#define chmax(a,b) ((a) = max((a),(b)))
#define in_range(x,l,r) ((l)<=(x) && (x)<(r))
#define printvec(a) rep(i,a) cout << a[i] << " \n"[i+1==(a).size()];
#define fs first
#define sc second
#define em emplace
#define eb emplace_back
#define sz size()
#define MP make_pair
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;

const ll INF = 1e8;
const D EPS = 1e-8;
const ll MOD = 1e9+7;

int main(){
  int n; cin >> n;
  for(int i=1;i<=n;i++){
    if(i*(i+1)/2 >= n){
      int k = i*(i+1)/2-n;
      for(int j=1;j<=i;j++){
        if(j!=k) cout << j << endl;
      }
      return 0;
    }
  }
}
