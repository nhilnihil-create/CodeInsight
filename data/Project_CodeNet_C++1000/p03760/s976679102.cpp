#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string o,e;
  cin >> o >> e;
  
  int ne = e.size();
  int no = o.size(); 
  string ans = "";
  for(int i = 0; i < ne; i++){
    ans += o[i];
    ans += e[i];
  }
  if(no != ne){
    ans += o[no-1];
  }
  
  cout << ans << endl;
    
}