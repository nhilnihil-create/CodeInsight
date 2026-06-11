#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int mod = 1000000007;
long long dp[100005];;

long long gcd(long long a,long long b){

  if(b == 0)
    return a;
  else return gcd(b,a%b);
}

int main(){

 long long a,b;
 cin>>a>>b;

 if(a>0 && b>0)
    cout<<"Positive"<<endl;
 else if(a<0 && b>0)
    cout<<"Zero"<<endl;
 else if(a<0 && b<0) {

    a = -1*a;
    b = -1*b;

    long long diff = (a-b)+1;

   // cout<<diff<<endl;

    if(diff %2 == 1)
        cout<<"Negative"<<endl;
    else
       cout<<"Positive"<<endl;
 }


return 0;
}
