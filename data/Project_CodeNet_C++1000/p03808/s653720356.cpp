#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

int main(){
  ll n,a[111111];
  cin>>n;
  ll suma=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    suma+=a[i];
  }

  if(suma%((n+1)*n/2)!=0){
    cout<<"NO"<<endl;
    return 0;
  }

  ll k=suma/((n+1)*n/2);
  ll f=1;
  for(int i=0;i<n;i++){
    if(a[i]<k)f=0;
    a[i]-=k;
  }
  
  //  dbg(k);
  
  if(f==0){
    cout<<"NO"<<endl;
    return 0;
  }

  int sumk=0;
  
  for(int i=0;i<n;i++){
    ll dif=abs(k-(a[(i+1)%n]-a[i]));
    //    dbg(dif);
    if(dif%n){
	 cout<<"NO"<<endl;
	 return 0;
    }
    sumk+=dif/n;
  }

  if(sumk==k)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  
  return 0;
}
