#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  int sum=0;
  vector<int> s(n);
  rep(i,n){cin >> s.at(i); sum+=s.at(i);}
  
  if(sum%10!=0) {cout<<sum; return 0;}

  sort(s.begin(), s.end());
  rep(i,n){
    if((sum-s.at(i))%10!=0) {cout<<sum-s.at(i); return 0;}
  }

  cout << 0;
  
}
