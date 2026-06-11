#include<bits/stdc++.h> 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vv = vector<vector<int>>;
using P = pair<int,int>;

bool func( int n ){
  if( n%10 == 9 ) return true;
  if( n == 0 ) return false;
  return func( n/10 );
}


int main(){
  int n;
  cin >> n;
  if( func(n) ){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
