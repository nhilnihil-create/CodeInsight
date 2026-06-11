#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using vi= vector<int>;
using vvi= vector<vi>;
using vd= vector<double>;
using vvd= vector<vd>;
using vc= vector<char>;
using vb= vector<bool>;
using vl= vector<ll>;
#define rep(i,x,n) for(int i=x; i<n; i++)
#define all(x) x.begin(), x.end()

int main(){
  char a,b;
  cin >> a >> b;
  if(a=='H'){
    cout << b;
  }else{
    if(b=='H'){
      cout << 'D';
    }else{
      cout << 'H';
    }
  }
  
  return 0;
}
