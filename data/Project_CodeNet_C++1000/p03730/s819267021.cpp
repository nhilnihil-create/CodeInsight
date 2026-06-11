#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main(){
int a,b,c;
cin>>a>>b>>c;

for(int i=0;i<a*b+1;i++){
    if((i*a+b*a)%b==c){
        cout<<"YES"<<endl;
        return 0;
    }
}

cout<<"NO";
  return 0;
}
