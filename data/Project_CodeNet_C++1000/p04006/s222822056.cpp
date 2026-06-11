#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
const ll INF = 1e17;

template <typename T>
class SegTree{
private:
  int n;
  vector<T> dat;
  T query_sub(int a, int b, int k, int l, int r);

public:
  SegTree(int _n);
  void update(int k, T a);
  T query(int a, int b);  // [a,b)
};

template <typename T>
SegTree<T>::SegTree(int _n){
   n = 1;
   while(n < _n) n *= 2;
   dat = vector<T>(2*n-1,INF);
}

template <typename T>
void SegTree<T>::update(int k, T a){
  k += n-1;
  dat[k] = a;
  while(k > 0){
    k = (k-1)/2;
    dat[k] = min(dat[2*k+1], dat[2*k+2]);
  }
}

template <typename T>
T SegTree<T>::query_sub(int a, int b, int k, int l, int r){
  if(r <= a || b <= l) return INF;
  if(a <= l && r <= b) return dat[k];
  T vl = query_sub(a, b, k*2+1, l, (l+r)/2);
  T vr = query_sub(a, b, k*2+2, (l+r)/2, r);
  return min(vl,vr);
}

template <typename T>
T SegTree<T>::query(int a, int b){
  return query_sub(a, b, 0, 0, n);
}

int main(){
    ll n; ll x;
    cin >> n >> x;
    SegTree<ll> st(n);
    rep(i,n) {
        ll a;
        cin >> a;
        st.update(i,a);
    }
    ll ans = INF;
    rep(i,n){
        ll c = x*i;
        rep(j,n){
            if(j-i < 0) c += min(st.query((j-i+n)%n,n),st.query(0,j+1));
            else c += st.query(j-i,j+1); 
        }
        ans = min(ans,c);
    }
    cout << ans << endl;
    return 0;
}