#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int k,s;
  cin>>k>>s;
  
  int cnt=0;
  for(int x=0;x<=k;x++){
    for(int y=0;y<=k;y++){
      if(0<=s-x-y && s-x-y<=k) cnt++;
    }
  }
  cout<<cnt<<endl;
       
  return 0;
}