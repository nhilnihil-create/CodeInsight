#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)



int main(){

  ll n;
  cin >> n;
  ll x[n];
  rep(i,n) cin >> x[i];
  ll L;
  cin >> L;
  ll Q;
  cin >> Q;
  ll a[Q],b[Q];
  rep(i,Q){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
    if(a[i]>b[i]) swap(a[i],b[i]);
  }
  //  cout << a[n-1] << endl;
	    
  ll logn=ceil(log2((double) n));
  ll dou_hotel[n][logn]; 
  rep(k,logn){
    rep(i,n){
      dou_hotel[i][k]=INT_MAX;
    }
  }
  rep(i,n){
    if(i==0) dou_hotel[i][0] = 0;
    else dou_hotel[i][0]=dou_hotel[i-1][0];
    ll t= dou_hotel[i][0];
    while(t+1<=n-1){
      if(x[t+1]-x[i]>L) break;
      t++;
      //      if(t==n-1) t=n*2LL;
    }
    dou_hotel[i][0]=t;
  }
  rep(k,logn-1){
    rep(i,n){
      if(dou_hotel[i][k]==INT_MAX){
	dou_hotel[i][k+1]==INT_MAX;
      }
      else{
	dou_hotel[i][k+1] = dou_hotel[dou_hotel[i][k]][k];
      }
    }
  }
  rep(j,Q){
    ll ind;
    ll ch=a[j];
    ll ans=0;
    for(ll i=logn-1; i>=0; i--){
      /*      if(dou_hotel[ch][i]==b[j]){
	ans+=pow(2,i);
	break;
	}*/
      /* if(i==0) ans++;
      else if(dou_hotel[ch][i]>=b[j] && dou_hotel[ch][i-1]<b[j]){	
	ans+=pow(2,i-1);
	ch=dou_hotel[ch][i-1];
	i++;
	}*/
      if(dou_hotel[ch][i]<b[j]){
	ans+=pow(2,i);
	ch=dou_hotel[ch][i];       
      }
    }
    cout << ans+1 << endl;   
  }
    

  
  return 0;

}
