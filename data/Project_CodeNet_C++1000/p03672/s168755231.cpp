#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main(){
string S;
cin>>S;
int ans=0;
for(int i=2;i<S.size();i+=2){
    bool flag=true;
    for(int k=0;k<i/2;k++){
if(S[k]!=S[k+i/2]){
    flag=false;
}
    }
if(flag){
    ans=i;
}
}
cout<<ans<<endl;

  return 0;
}
