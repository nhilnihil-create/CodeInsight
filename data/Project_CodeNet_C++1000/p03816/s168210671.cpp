#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> t(100001);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    t.at(a.at(i))++;
  }
  
  int k=0,cnt =0;
  for(int i=0;i<100001;i++){
    if(t.at(i) >= 3){
      if(t.at(i)%2 == 0) t.at(i) = 2;
      else t.at(i) = 1;
    }
    
    if(t.at(i) == 2) k++;
    
    if(t.at(i) <= 2 && t.at(i) > 0) cnt++;
  }
  
  if(k%2 == 1) cnt--;
  
  cout << cnt << endl;  
  
  return 0;
}
