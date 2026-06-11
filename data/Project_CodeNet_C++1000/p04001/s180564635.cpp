#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n=0;
  n=s.size();
  if(n==1){
    cout<<stoi(s)<<endl;
    return 0;
  }
  long long ans=0;
  for(int i=0;i<(1<<(n-1));i++){
    int las=-1;
    bitset<10> bit(i);
    for(int j=0;j<n-1;j++){
      if(bit.test(j)){
        string sub=s.substr(las+1,j-las);
        ans+=stoll(sub);
        las=j;
      }
    }
    ans+=stoll(s.substr(las+1,n-1-las));
               }
               cout<<ans<<endl;
               }