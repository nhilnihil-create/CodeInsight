#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n,a,b,sum=0;
  cin>>n;
  while(n--) { 
    cin>>a>>b;
    sum+=(b-a)+1;
    }
  cout<<sum<<endl;
  
  return 0;
}
