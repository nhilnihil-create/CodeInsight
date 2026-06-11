#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >>h >> w;
  string s;
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      cin >> s;
      if(s=="snuke"){
	char a='A'+j;
	cout << a << i+1 << endl;
	return 0;
      }
    }
  }
  return 0;
}
