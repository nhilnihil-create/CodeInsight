#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main(){
ll a,b,c;
cin>>a>>b>>c;
ll count=0;
while(a%2==0&&b%2==0&&c%2==0){
ll A=a,B=b,C=c;
a=(B+C)/2;
b=(A+C)/2;
c=(A+B)/2;
count++;
//cout<<a<<b<<c<<endl;
if(count==100007){
    cout<<-1<<endl;
    return 0;
}
}


cout<<count<<endl;
  return 0;
}
