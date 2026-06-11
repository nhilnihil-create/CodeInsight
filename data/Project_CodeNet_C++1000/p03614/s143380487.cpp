#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i=0;i<n;i++) cin >> p[i];
  int tmp;
  int ans=0;
  for(int i=0;i<n-2;i++){
    if(p[i]==i+1){
      ans++;
      tmp=p[i];
      p[i]=p[i+1];
      p[i+1]=tmp;
    }
  }
  if(p[n-1]==n||p[n-2]==n-1){
    ans++;
  }
  cout << ans << endl;
  return 0;
}
