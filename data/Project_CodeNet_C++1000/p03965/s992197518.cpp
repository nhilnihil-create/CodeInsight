#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
  cin>>s;
  int N=s.size();
  int ans=0;
  for(int i=0;i<N;i++)
    if(s.at(i)=='g')
      ans++;
  else
    ans--;
  cout<<ans/2<<endl;
    return 0;
}
