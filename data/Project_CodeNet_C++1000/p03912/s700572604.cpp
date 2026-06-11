#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef pair<ll,ll> pll;

#define reps(i,f,n) for(int i = int(f); i <= int(n); i++)
#define rep(i,n) reps(i,0,int(n)-1)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)

#define all(x) (x).begin(),(x).end()
#define X first
#define Y second

#define sz size()
#define eb emplace_back
#define pb push_back

int hi[100001];

int main(void){
  int n, m;
  int a;
  int ans = 0;
  cin >> n >> m;
  vector<int> q[100001];
  rep(i,n){
    cin >> a;
    q[a%m].push_back(a);
    hi[a]++;
  }
  rep(i,m){
    sort(all(q[i]));
  }

  ans += q[0].sz/2;
  
  if(m%2==0){
    //偶数
    for(int i = 1; i < m/2; i++){
      int use = min(q[i].sz, q[m-i].sz);

      if(q[i].sz>use){
        int res = q[i].sz - use;
        if(res > 1){
          rep(j,q[i].sz){
            while(res>1&&hi[q[i][j]]>1){
              hi[q[i][j]]-=2;
              ans++;res-=2;
            }
          }
        }
      }
      if(q[m-i].sz>use){
        int res = q[m-i].sz - use;
        if(res > 1){
          rep(j,q[m-i].sz){
            while(res>1&&hi[q[m-i][j]]>1){
              hi[q[m-i][j]]-=2;
              ans++;res-=2;
            }
          }
        }
      }
      ans+= use;
    }
    ans += q[m/2].sz/2;
  }else{
    for(int i = 1; i <= m/2; i++){
      int use = min(q[i].sz, q[m-i].sz);
      if(q[i].sz>use){
        int res = q[i].sz - use;
        if(res > 1){
          rep(j,q[i].sz){
            while(res>1&&hi[q[i][j]]>1){
              hi[q[i][j]]-=2;
              ans++;res-=2;
            }
          }
        }
      }
      if(q[m-i].sz>use){
        int res = q[m-i].sz - use;
        if(res > 1){
          rep(j,q[m-i].sz){
            while(res>1&&hi[q[m-i][j]]>1){
              hi[q[m-i][j]]-=2;
              ans++;res-=2;
            }
          }
        }
      }
      ans+= use;
    }
  }

  cout << ans << endl;
  return 0;
}
