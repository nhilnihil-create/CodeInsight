#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  vector<char> a{'C','O','D','E','F','E','S','T','I','V','A','L','2','0','1','6'};
  int n=0;
  for(int i=0;i<16;i++){
    if(s.at(i)!=a.at(i))n++;
  }
  cout<<n<<endl;
}
