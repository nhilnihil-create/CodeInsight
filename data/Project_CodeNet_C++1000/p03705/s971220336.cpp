#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  ll N,A,B;
  cin >> N >> A >> B;
  ll ans = 0;
  if(N == 1 && (B > A)){
    ans = 0;
  } else if(A > B){
    ans = 0;
  } else { 
    ans = (A+B*(N-1)) - (B+A*(N-1)) + 1;
  }
  cout << ans << endl;
}
