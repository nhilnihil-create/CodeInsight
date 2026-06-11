//Buble sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  for(int i = 0; n > i; i++){
    cin>>a[i];
    b[i] = a[i];
  }
  sort(b.begin(),b.end());
  for(int i = 0; n > i; i++){
    a[i] = lower_bound(b.begin(),b.end(),a[i])-b.begin();
  }
  int ans = 0;
  for(int i = 0; n > i; i++){
    if(i%2 != a[i]%2){
      ans++;
    }
  }

  
  cout << ans/2 << endl;
}