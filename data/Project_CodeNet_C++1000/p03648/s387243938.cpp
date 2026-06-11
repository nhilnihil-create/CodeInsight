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
  ll k,p,q;
  cin>>k;
  cout<<50<<endl;
  p=(k-1)/50+1;
  q=50*p-k;
  fr(i,q) cout<<p+q-2<<" ";
  fr(i,50-q) cout<<p+q+49<<" ";
  cout<<endl;
}