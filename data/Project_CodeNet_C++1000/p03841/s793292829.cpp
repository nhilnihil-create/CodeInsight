#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int tx;
  pair<int,int> x[n];
  rep(i,n){
    cin >> tx;
    x[i]=mp(--tx, i+1);
  }
  sort(x,x+n);
  deque<int> mar;
  deque<pair<int, int> > Rque;
  int ans[n*n];
  rep(i,n*n) ans[i]=-1;
  int pre=0;
  rep(i,n){
    int pos=x[i].first;
    int ind=x[i].second;
    for(int j=pre; j<pos; j++) mar.pb(j);
    ans[pos]=ind;
    int c=ind-1;
    while(!mar.empty()){
      if(c==0) break;
      ans[mar.front()]=ind;
      c--;
      mar.pop_front();
    }
    if(c>0){
      cout << "No" << endl;
      return 0;
    }
    rep(j,n-ind) Rque.push_front(mp(pos+1, ind));
    pre=pos+1;
  }
  for(int j=pre; j<n*n; j++) mar.pb(j);
  //  rep(i,n*n) cout << ans[i] << " ";
  //  cout << ""<<endl;
  for(int i=mar.size()-1;i>=0;i--){
    pair<int,int> pu=Rque.front();Rque.pop_front();
    if(pu.first>mar[i]){
      cout << "No" << endl;
      return 0;
    }
    //    cout << mar[i] << " ni "  << pu.second << " wo " <<endl;
    ans[mar[i]]=pu.second;
  }
  cout << "Yes" << endl;
  rep(i,n*n) cout << ans[i] << " ";
  cout << "" << endl;
  return 0;
    
  
}
