#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string a,b; cin >> a >> b;
  bool equal = false;
  if(a.size()<b.size()){
    cout << "LESS" << endl;
    return 0;
  }
  else if(a.size()>b.size()){
    cout << "GREATER" << endl;
    return 0;
  }
  else{
    rep(i,a.size())
      if(a[i]>b[i]){
	cout << "GREATER" << endl;
	return 0;
      }
      else if(a[i]<b[i]){
	cout << "LESS" << endl;
	return 0;
      }
      else{
	equal = true;
      }
  }
	
  if(equal) cout << "EQUAL" << endl;
  
  return 0;
}
