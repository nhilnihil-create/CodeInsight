#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  string s;
  cin>>s;
  int d=0,p=0;
  rep(i,s.size()){
    if(s[i]=='g'){
      if(d>0){
	p++;
	d--;
      }
      else{
	d++;
      }
    }
    else{
      if(d>0){
	d--;
      }
      else{
	p--;
	d++;
      }
    }
  }
  cout<<p<<endl;
  return 0;
}