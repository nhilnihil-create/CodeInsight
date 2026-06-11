#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int N, P; cin >> N >> P;
  int a;
  map<int,int> cnt; 
  rep(i,N) {
    cin >> a;
    cnt[a%2]++;
  }
  ll retval;
  
  if (cnt[1]==0 && P==1) retval = 0;
  else if (cnt[1]==0 && P==0) retval = (1ll<<cnt[0]);
  else retval = (1ll<<(cnt[0]+cnt[1]-1));
  
  cout << retval << endl;




  // cout << fixed << setprecision(10);
  
  return 0;
}

