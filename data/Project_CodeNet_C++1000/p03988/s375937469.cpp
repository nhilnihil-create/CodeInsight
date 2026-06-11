#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  map<int, int> mp;
  for(int i=0;i<n;i++){
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a,a+n);
  int dia=a[n-1]+1,tmp=a[n-1];
  while(dia>0){
    if(dia>2){
      if(mp[tmp]<2){
        cout << "Impossible\n";
        return 0;
      }else{
        dia-=2;
      }
    }else if(dia==2){
      if(mp[tmp]==2){
        dia-=2;
      }else{
        cout << "Impossible\n";
        return 0;
      }
    }else{
      if(mp[tmp]==1){
        dia--;
      }else{
        cout << "Impossible\n";
        return 0;
      }
    }
    tmp--;
  }
  cout << "Possible\n";
  return 0;
}
