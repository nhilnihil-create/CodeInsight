#include<iostream>
using namespace std;
typedef long long ll;
signed main(){
  ll n;
  string s;
  bool a,b;
  cin >> n >> s;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      string tmp;
      tmp += (i==0)?'S':'W';
      tmp += (j==0)?'S':'W';
      for(int k=2;k<n;k++){
        if(tmp[k-1]=='S'){
          if(s[k-1]=='o'){
            tmp+=tmp[k-2];
          }else{
            tmp+=(tmp[k-2]=='W')?'S':'W';
          }
        }else{
          if(s[k-1]=='x'){
            tmp+=tmp[k-2];
          }else{
            tmp+=(tmp[k-2]=='W')?'S':'W';
          }
        }
      }
      if(tmp[0]=='S'){
        a =((s[0]=='o'&&tmp[1]==tmp[n-1])
            ||(s[0]=='x'&&tmp[1]!=tmp[n-1]));
      }else{
        a =((s[0]=='x'&&tmp[1]==tmp[n-1])
            ||(s[0]=='o'&&tmp[1]!=tmp[n-1]));
      }
      if(tmp[n-1]=='S'){
        b =((s[n-1]=='o'&&tmp[n-2]==tmp[0])
            ||(s[n-1]=='x'&&tmp[n-2]!=tmp[0]));
      }else{
        b =((s[n-1]=='x'&&tmp[n-2]==tmp[0])
            ||(s[n-1]=='o'&&tmp[n-2]!=tmp[0]));
      }
      if(a&&b){
        cout << tmp<<endl;
        return 0;
      }
    }
  }
  cout <<"-1\n";
}
