#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main(){
int n;
cin>>n;
string s;
cin>>s;
int count=0,ans=0;
rep(i,n){
    if(s[i]=='I'){
        count++;
    }else{
        count--;
    }
    ans=max(ans,count);
}

cout<<ans<<endl;
  return 0;
}
