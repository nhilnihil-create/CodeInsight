#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ll N;
  cin >> N;
  ll a[3*N];
  rep(i,3*N) cin >> a[i];
  ll smae[N+1];//前N+i要素のうちのN要素の総和の最大値
  ll sato[N+1];//後ろN+i要素うちのN要素の総和の最小値
  rep(i,N+1) smae[i]=0;
  rep(i,N+1) sato[i]=0;
  //  cout << "mae" << endl;
  priority_queue<int, vector<int>, greater<int> > quemae;
  priority_queue<int> queato;
  rep(i,N) quemae.push(a[i]);
  rep(i,N) queato.push(a[2*N+i]);
  rep(i,N+1){
    if(i==0) rep(j,N)smae[i]+=a[j];
    else if(a[N-1+i]<quemae.top()){
      smae[i]=smae[i-1];
    }
    else {
      int mae_min=quemae.top();
      quemae.pop();
      smae[i]=smae[i-1]-mae_min+a[N-1+i];
      quemae.push(a[N-1+i]);
    }
    
    //    cout << smae[i] << endl;
  }
  rep(i,N+1){
    if(i==0) rep(j,N) sato[i]+=a[2*N+j];
    else if(a[2*N-i]>queato.top()){
      sato[i]=sato[i-1];
    }
    else{
      int ato_min=queato.top();
      queato.pop();
      sato[i]=sato[i-1]-ato_min+a[2*N-i];
      queato.push(a[2*N-i]);
    }
    //        cout << a[2*N-i] << endl;
    //    cout << sato[i] << endl;
  }
  ll ans=-INT_MAX*(N*1LL);
  rep(i,N+1){
    ans = max(smae[i] - sato[N-i],ans);
  }
  cout << ans << endl;

  
  return 0;

}
