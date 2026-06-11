#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

ll findpow(ll a,ll b){
    ll cnt=0,i,j;
    while(a>1){
        a=a/b;
        cnt++;
    }
    return cnt;
}

int main(){
    ll i,j,k,sum=0,n;
  cin>>i>>j>>n;
  cout<<(i+j)*(n/2)<<endl;
    
	return 0;
}