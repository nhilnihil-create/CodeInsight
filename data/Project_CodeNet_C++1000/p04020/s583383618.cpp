#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  long long now=0,ans=0;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    now+=x;
    if(x==0){
      ans+=(now/2);
      now=0;
    }
  }
  ans+=now/2;
  cout << ans << endl;
}