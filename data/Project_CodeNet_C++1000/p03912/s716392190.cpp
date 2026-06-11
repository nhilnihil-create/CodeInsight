#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  int x[n];
  rep(i,n) cin >> x[i];
  sort(x,x+n);
  int c[m],kumi[m];
  rep(i,m){
    c[i]=0;
    kumi[i]=0;
  }
  rep(i,n){
    c[x[i]%m]++;   
  }
  rep(i,n-1){
    if(x[i]==x[i+1]){
      kumi[x[i]%m]++;
      i++;
    }
  }
  //  rep(i,m) cout << i << " " << c[i] << endl;
  int ans=0;
  rep(i,m/2+1){//0と半分
    if(i==0){
      ans+=c[i]/2;
    }
    else if(m%2==0 && i==m/2){
      ans+=c[i]/2;
    }
    else if(c[i]>=c[m-i]){
      ans+=c[m-i];
      ans+=min(kumi[i],(c[i]-c[m-i])/2);
    }else{
      ans+=c[i];
      ans+=min(kumi[m-i],(c[m-i]-c[i])/2);
    }
    //    cout << ans << endl;
  }
  cout << ans << endl;
  
  return 0;
    

}
