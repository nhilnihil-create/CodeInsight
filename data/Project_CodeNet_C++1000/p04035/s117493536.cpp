// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,l,ind=-1;
  cin >> n >> l;
  ll a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(i!=0){
      if(a[i]+a[i-1]>=l){
        ind = i;
      }
    }
  }
  if(ind==-1){
    cout << "Impossible\n";
    return 0;
  }
  cout <<"Possible\n";
  for(int i=1;i<ind;i++){
    cout << i<<endl;
  }
  for(int i=n-1;i>ind;i--){
    cout << i<<endl;
  }
  cout << ind <<endl;
}
