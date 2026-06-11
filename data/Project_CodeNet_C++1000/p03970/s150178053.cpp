#include<iostream>
#include<string>
using namespace std;
int main(){
  string s,r = "CODEFESTIVAL2016";cin >> s;int ans=0,i;
  for(i=0;i<16;i++){
    ans += (s[i] != r[i]);
  }
  cout << ans << endl;
}
  