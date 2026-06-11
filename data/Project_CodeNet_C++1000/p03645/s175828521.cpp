#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
 
int main(){
  int n,m,a,b;
  cin >> n >> m;
  
  bitset<200000> first;
  bitset<200000> second;
  
  rep(i,m){
    cin >> a >>b;
    if(a==1)
      first.set(b,1);
    if(b==n)
      second.set(a,1);  
  }
  
  first=first&second;
  
  
  if(first.any())
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  
  
  
  
}