#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
 string S; cin>>S;
 int N=S.size();

 string ans;

 if(S.front()==S.back()){
  ans = (N%2==1) ? "Second" : "First";
 }
 else{
  ans = (N%2==1) ? "First" : "Second";
 }

 cout<<ans<<endl;

 return 0;
}


