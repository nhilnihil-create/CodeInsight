#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

/*
 * 3 2 5
 * 2 2 5
 * 2 2 1
 * 1 2 1
 */

int N;
vector<i64> A;
int main(){
  cin >> N;
  A.resize(N);

  rep(i,0,N - 1){
    cin >> A[i];
  }
  i64 ans = A[0] - 1;
  i64 MAX = 1;

  auto div = [](i64 a,i64 b){
    return  a / b + min(a % b,1LL);
  };
  rep(i,1,N - 1){
    if(A[i] < MAX + 1) continue;
    if(MAX + 1 == A[i]){
      MAX++;
    }
    else{
      ans += div(A[i] - (MAX + 1),(MAX + 1));
    }
  }
  cout << ans << endl;
}
/*15
3=2=1
1
4=1
1
5=3=1
9=7=5=3=1
2
6=1
5
3
5
8
9
7
9
*/
