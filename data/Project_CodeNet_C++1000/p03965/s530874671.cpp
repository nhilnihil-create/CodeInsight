#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    string s;
    cin>>s;
    sort(begin(s),end(s));
  int N;
  if(s.find("p")==string::npos){
    N=0;
  }else{
    N=s.size()-s.find("p");
  }
   int ans=s.size()/2;
   cout<<ans-N<<endl;
}