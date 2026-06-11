#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int W,A,B;
  cin >> W >> A >> B;

  int ans = 0;
  if(A <= B){
    if(A+W <= B){
      ans = B - A - W;
    } else { 
      ans = 0;
    }
  } else { 
    if(B+W <= A){
      ans = A - B - W;
    } else { 
      ans = 0;
    }
  }
  cout << ans << endl;
}
