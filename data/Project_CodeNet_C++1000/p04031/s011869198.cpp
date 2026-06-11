#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
#define vecmin(A) *min_element(A.begin(),A.end())
#define vecmax(A) *max_element(A.begin(),A.end())
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans = 1000000000;
  for(int i = -100;i<=100;i++){
    int sub_ans = 0;
    rep(j,n){
      sub_ans += (i - a[j])*(i - a[j]);
    }//j
    ans = min(sub_ans,ans);
  }//i
  cout << ans << endl;
}