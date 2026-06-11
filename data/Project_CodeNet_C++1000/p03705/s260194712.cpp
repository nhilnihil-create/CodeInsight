#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main(){
ll n,a,b;
cin>>n>>a>>b;
if(a>b){
    cout<<0<<endl;
    
}else if(a==b){
    cout<<1<<endl;
}else if(a!=b&&n==1){
    cout<<0<<endl;
}

else{
    ll MAX=b+a*(n-1),MIN=a+b*(n-1);
    cout<<-MAX+MIN+1<<endl;
}



  return 0;
}
