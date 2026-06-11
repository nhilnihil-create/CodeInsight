#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

template<typename T>
struct BIT {
    int n;
    vector<T> dat;
 
    BIT(int n=0){
        initialize(n);
    }
 
    void initialize(int nin){
        n = nin;
        dat.resize(n);
        for(int i = 0; i<n; i++) dat[i] = 0;
    }
 
    T sum(int i){
        T s = 0;
        while(i >= 0){
            s += dat[i];
            i = (i & (i+1)) - 1;
        }
        return s;
    }
 
    T sum_between(int i, int j){
        if(i > j) return 0;
        return sum(j) - sum(i-1);
    }
 
    void plus(int i, T x){
        while(i < n){
            dat[i] += x;
            i |= i+1;
        }
    }
 
    // a[0]+...+a[ret+1] >= x
    int lower_bound(T x){
        int ret = -1;
        int k = 1;
        while(2*k <= n) k <<= 1;
        for( ;k>0; k>>=1){
            if(ret+k < n && dat[ret+k] < x){
                x -= dat[ret+k];
                ret += k;
            }
        }
        return ret + 1;
    }
};

int main(){
  int n,m;cin>>n>>m;
  int l[n],r[n];
  rep(i,n){
    cin>>l[i]>>r[i];
    l[i]--;r[i]--;
  }
  vector<int> w[m];
  rep(i,n)w[r[i]-l[i]].push_back(i);
  BIT<int> bit(m+1);
  int stablen=n;
  rep(i,m){
    int s=0;
    int k=i+1;
    for(int x=k;x<=m;x+=k){
      s+=bit.sum(x-1);
    }
    cout<<stablen+s<<endl;

    rep(j,w[i].size()){
      int lri=w[i][j];
      bit.plus(l[lri],1);
      bit.plus(r[lri]+1,-1);
      stablen--;
    }
  }
}


      