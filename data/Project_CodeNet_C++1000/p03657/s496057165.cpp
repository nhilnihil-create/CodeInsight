#include<bits/stdc++.h> 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vv = vector<vector<int>>;
using P = pair<int,int>;

int main(){
  int a,b;
  cin >> a >> b;
  if( a%3 == 0 || b%3 == 0 || (a+b)%3 == 0 ){
    cout << "Possible" << endl;
  }else{
	cout << "Impossible" << endl;
  }
  return 0;
}
