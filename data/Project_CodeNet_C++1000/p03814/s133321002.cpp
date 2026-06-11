#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  string s;
  cin >> s;
  int n=s.size();
  int a=2200000;
  int b=0;

  rep(i,n){
     if(s.at(i)=='A'){
        a=min(a,i);
     }
     else if(s.at(i)=='Z'){
        b=max(b,i);
     }
  }
  cout << b-a+1 << endl;

}