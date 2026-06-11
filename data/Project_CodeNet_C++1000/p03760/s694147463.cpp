#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  string o,e;
  cin >> o >> e;
  int n=o.size();
  int m=e.size();
  if(n==m){
     rep(i,n){
        cout << o[i] << e[i];
     }
     cout << endl;
  }
  else if(n>m){
     rep(i,m){
        cout << o[i] << e[i];
     }
     cout << o[n-1] << endl;
  }
  
}