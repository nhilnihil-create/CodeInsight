#include <bits/stdc++.h>
using namespace std;
#define ll long long

void fun(ll n , ll s){
 ll a[n];
 ll sum=0;
 ll r,l;
 l=0;
 r=n-1;
 ll ans=n;
 for(ll i=0;i<n;i++){cin>>a[i];sum+=a[i];}
 if(sum<s)ans=0;
 while(l<=r && ans){
 if(a[l]<a[r]&&sum-a[l]>=s){

    sum-=a[l++];ans--;

 }else if(sum-a[r]>=s){
    sum-=a[r--];ans--;

 }else break;;;


}
 cout << ans << "\n";
}
int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 ll n,m;
 cin >>n>>m;
 bool a[n];
 ll b[n];
 for(ll i=0;i<n;i++){
  a[i]=false;
  b[i]=1;
 }
 a[0]=true;
 for(ll i=0;i<m;i++){
    ll x,y;
    cin>>x>>y;
    x--;
    y--;
    if(a[x])a[y]=true;
    b[x]--;
    b[y]++;
    if(b[x]==0)a[x]=false;
 }
 ll c=0;
 for(ll i=0;i<n;i++){
    if(a[i]&&b[i]>0)c++;
 }
 cout << c;
}
