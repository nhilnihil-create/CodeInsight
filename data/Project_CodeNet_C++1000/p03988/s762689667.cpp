#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a;
  for(int i=0;i<n;i++){
      int x;
      cin>>x;
      a.push_back(x);
  }
  sort(a.begin(),a.end());
  bool suc=false;
  if(a[0]==1){
      if(n==2){
          if(a[1]==1) suc=true; 
      }else{
          if(a[1]==2&&a[n-1]==2) suc=true;
      }
  }else{
      int now=0;
      for(int i=0;i<n;i++){
          if(a[i]==a[0]) now++;
          else break;
      }
      if(now<=2){
          int cost=a[0]+a[0]-1;
          if(now==1) cost++;
          if(a[n-1]!=cost);
          else{
          int tmp=1;
          for(int i=now+1;i<n;i++){
              if(a[i]!=a[i-1]){
                  if(tmp==1||a[i-1]+1!=a[i]) break;
                  tmp=1;
              }else tmp++;
              if(i==n-1) suc=true;
          }
          }
      }
  }

  if(suc) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;

  return 0;
}
