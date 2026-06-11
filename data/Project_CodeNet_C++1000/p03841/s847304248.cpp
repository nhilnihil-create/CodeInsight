#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define ALL(a) a.begin(), a.end()
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll N,M,H,W,K,Q,A,B;

int main(){
    cin>>N; 
    vec x(N), ans(0), ord(N), oinv(N); 
    rep(i,N) cin>>x[i], --x[i], ord[i] = i; 
    sort(ALL(ord), [&](ll a, ll b){ 
      return x[a] < x[b]; 
    }); 
  rep(i,N) oinv[ord[i]] = i;
    rep(i,N) rep(j,ord[i]) ans.push_back(ord[i]);
    rep(i,N) { 
        ll num= ord[i], nx = x[num]; 
        if(nx > ans.size()){ 
          cout<<"No"<<endl; 
          return 0; 
        }else if(nx < ans.size()){
          ll tar = ans[nx]; 
          if(oinv[tar] <= i && nx < N*(N-1)/2 + i){ 
            cout<<"No"<<endl; 
            return 0; 
          }
      } 
      ans.insert(ans.begin() + nx, num); 
      rep(j, N-num-1) ans.push_back(num);
    } 
  cout<<"Yes"<<endl; 
  rep(i,N*N){ 
    cout<<ans[i] + 1; 
    i == N*N - 1 ? cout<<endl : cout<<' ';
  } 
}