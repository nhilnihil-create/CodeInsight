#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1<<30;

int main(){
  int h, w;cin>>h>>w;
  for(int i=0;i<h;i++){
  	for(int j=0;j<w;j++){
      string s;cin>>s;
      if(s=="snuke")cout<<char('A'+j)<<i+1<<endl;
    }
  }
}