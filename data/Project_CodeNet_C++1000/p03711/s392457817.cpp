#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const int INF = 1000000001;

int main(){
  int a, b;
  cin >> a >> b;
  if(a==4||a==6||a==9||a==11){
    a=0;
  }else if(a!=2){
    a=1;
  }
  if(b==4||b==6||b==9||b==11){
    b=0;
  }else if(b!=2){
    b=1;
  }
  if(a==b) cout << "Yes"<<endl;
  else cout << "No" <<endl;
}