#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int H,W;
  cin >> H >> W;
  vector<string> A(H);
  map<char,int> mp;
  REP(i, H) cin >> A[i];
  REP(i,H){
    REP(j,W){
      mp[A.at(i).at(j)]++;
    }
  }
  
  int Four = (H/2)*(W/2);
  int Two=0,One=0;
  if(H%2==1&&W%2==0){
    Two = W/2;
  }
  if(H%2==0&&W%2==1){
    Two = H/2;
  }
  if(H%2==1&&W%2==1){
    Two = H/2+W/2;
    One = 1;
  }

  int p=0,q=0,r=0;
  for(auto x:mp){
    if(x.second%4==0){
      p+=x.second/4;
    }else if(x.second%2==0){
      q+=(x.second%4)/2;
      p+=x.second/4;
    }else{
      r++;
      int y = x.second-1;
      if(y%4==0){
        p+=y/4;
      }else if(y%2==0){
        q+=(y%4)/2;
        p+=y/4;
      }
    }
  }

  int flag = 0;
  if(r!=One){
    flag = 1;
  }else if(Two<q){
    flag=1;
  }else{
    Two-=q;
    if(Two%2!=0||Two/2>p){
      flag = 1;
    }else{
      p-=Two/2;
      if(p!=Four){
        flag=1;
      }
    }
  }

  if(flag==0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}