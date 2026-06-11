#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  if(n==1){
    cout << 1 << endl;
    return 0;
  }
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  int ans=1,x=0;
  while(x+1<n&&a.at(x)==a.at(x+1))
    x++;
  bool zok;
  if(x+1<n)
    zok=a.at(x)<a.at(x+1);
  for(int i=x;i<n-1;i++){
    if(zok){
      if(a.at(i)>a.at(i+1)){
        ans++;
        i++;
        while(i+1<n&&a.at(i)==a.at(i+1))
          i++;
        if(i+1<n)
          zok=a.at(i)<a.at(i+1);
      }
    }else{
      if(a.at(i)<a.at(i+1)){
        ans++;
        i++;
        while(i+1<n&&a.at(i)==a.at(i+1))
          i++;
        if(i+1<n)
          zok=a.at(i)<a.at(i+1);
      }
    }
  }
  cout << ans << endl;
  return 0;
}