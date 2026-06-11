#include <iostream>
using namespace std;

typedef long long ll;

int main(){
  ll n;
  cin >> n;
  ll a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  ll rem=n*(n+1)/2;
  ll sum=0;
  for(int i=0;i<n;i++){
    sum+=a[i];
  }
  if(sum%rem){
    cout << "NO" << endl;
  }
  else{
    ll use=sum/rem;
    ll pl[n],mi[n];
    bool check=true;
    for(int i=0;i<n;i++){
      ll dis;
      if(i<n-1){
        dis=a[i+1]-a[i];
      }
      else{
        dis=a[0]-a[i];
      }
      ll s=use-dis;
      if(s%n||s/n>use||s/n<0){
        check=false;
      }
      else{
        pl[i]=use-s/n;
        mi[i]=s/n;
      }
    }
    if(!check){
      cout << "NO" << endl;
    }
    else{
      ll x=0,y=0;
      for(int i=0;i<n;i++){
        x+=pl[i];
        y+=mi[i];
      }
      if(x==use*(n-1)&&y==use){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    }
  }
}