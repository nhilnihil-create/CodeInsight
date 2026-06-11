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
  if(a%3==0 || b%3==0||(a+b)%3==0){
    cout << "Possible" <<endl;
  }else{
    cout << "Impossible" <<endl;
  }
}