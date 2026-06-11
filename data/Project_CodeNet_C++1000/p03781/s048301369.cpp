#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

int main(){
  ll x;
  cin>>x;
  fr(i,1e5){
    if((i*(i+1))/2>=x){cout<<i<<endl;return 0;}
  }
}