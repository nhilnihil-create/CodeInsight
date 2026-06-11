#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N = 200010;
const int INF = 1LL<<55;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
typedef pair<int,int> P;
typedef long long ll;
ostream& operator<<(ostream& o,P p){return o<<"("<<p.first<<","<<p.second<<")";}
istream& operator>>(istream& i,P &p){return i>>p.first>>p.second;}
template<class T> istream& operator>>(istream& i,vector<T> &a){for(auto &t:a)cin>>t;return i;}
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
template<class T> void prArr(T a,string s=" "){int i=0;for(auto t:a)cout<<(i++?s:"")<<t;cout<<endl;}


class CumulativeSum{
public:
  vector<int> sum;
  CumulativeSum(){}
  CumulativeSum(vector<int> A){
    int n = A.size();
    sum.resize(n+1,0);
    for(int i=1;i<=n;i++) sum[i] += sum[i-1] + A[i-1];
  }
  int get(int l,int r){return sum[r] - sum[l];} //[)
};

CumulativeSum sum;


int n;
vector<int> A;
vector<char> op;
int f[2] = {1,-1};

int used[N][3],mem[N][3];

int dfs(int idx,int cnt){
  if(cnt == 2) return sum.get(idx,n);
  if(idx == n) return 0;
  if(used[idx][cnt]++) return mem[idx][cnt];
  
  char ch = op[idx-1];
  cnt += ch == '-';
  int res = 0;
  int val = f[cnt%2] * A[idx];
  if(cnt) Max(res,val + dfs(idx+1,cnt-1));
  Max(res,val + dfs(idx+1,cnt));
  return mem[idx][cnt] = res;
}


signed main(){
  cin>>n;
  A.resize(n);
  op.resize(n);
  for(int i=0;i<n;i++) {
    cin>>A[i];
    if(i!=n-1) cin>>op[i];
  }
  sum = CumulativeSum(A);
  cout<<A[0] + dfs(1,0)<<endl;
  return 0;
}
