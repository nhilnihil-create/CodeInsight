#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
  cin>>s;
  int K;
  cin>>K;
  int N=s.size();
  for(int i=0;i<N-1;i++){
  if(s.at(i)!='a' &&26-(s.at(i)-'a')<=K){
  K-=(26-(s.at(i)-'a'));
    s.at(i)='a';
  }
  }s.at(N-1)=char('a'+(s.at(N-1)-'a'+K)%26);
  cout<<s<<endl;
   return 0;
}