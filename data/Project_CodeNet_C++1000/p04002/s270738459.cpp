#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define P pair<ll,ll>
#define pb push_back
#define mk make_pair
using namespace std;
const int INF = 1 << 20;

typedef long long ll;




int main(){
  ll h,w,n;
  int dir[3] = {-1,0,1};
  cin >> h >> w >> n;
  vector <P> d;
  if(n > 0){
    REP(i,n){
      int a,b;
      cin >> b >> a;
      REP(j,3){
	REP(k,3){
	  if((a+dir[j] >= 2) && (a+dir[j] <= w-1) && (b+dir[k] <= h-1) && (b+dir[k] >= 2)){
	    d.pb(mk(a+dir[j],b+dir[k]));
	    //cout << a+dir[j] << "             " << b+dir[k] << endl;
	  }
	}
      }
  }
    //cout << 1 << endl;
    if(d.size() > 0)
      sort(d.begin(),d.end());
    ll res[10] = {0};
    
    P before = d[0];
    ll num = 1;
    /*REP(i,d.size()){
      cout << d[i].first << "   " << d[i].second << endl;
      }
    */
    //cout << 1 << endl;
    for(int i = 1;i < d.size();i++){
      if(before == d[i]){
	num++;
      }
      else{
	before = d[i];
	res[num]++;
	num = 1;
	
      }
    }
    //cout << 1 << endl;
    res[num]++;
    ll sum = 0;
    for(int i = 1;i < 10;i++)
      sum += res[i];
    res[0] = (h-2)*(w-2) - sum;
    REP(i,10){
      cout << res[i] << endl;
    }
  }
  else{
    cout << (h-2)*(w-2) << endl;
    REP(i,9){
      cout << 0 << endl;
    }
  }
  return 0;
}
