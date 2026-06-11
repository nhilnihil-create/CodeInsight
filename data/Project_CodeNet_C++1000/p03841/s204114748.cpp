#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#include <iomanip>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;cin>>N;
  vector<Pii> x(N);
  vint ans(N*N);
  repeat(i,N){
    cin>>x[i].first;x[i].first--;
    x[i].second = i+1;
    ans[x[i].first]=x[i].second;
  }
  sort(x.begin(),x.end());
  int l=0;
  repeat(i,N){
    repeat(j,x[i].second-1){
      while(ans[l]!=0)l++;
      ans[l]=x[i].second;
    }
  }
  int r=N*N-1;
  for(int i=N-1;i>=0;i--){
    repeat(j,N-x[i].second){
      while(ans[r]!=0)r--;
      ans[r]=x[i].second;
    }
  }
  bool isok=true;
  vint cnt(N,0);
  int idx=0;
  repeat(i,N*N){
    cnt[ans[i]-1]++;
    if(i==x[idx].first){
      isok &= cnt[ans[i]-1]==ans[i];
      idx++;
    }
  }
  repeat(i,N){
    isok &= cnt[i]==N;
  }
  if(isok){
    cout << "Yes" << endl;
    repeat(i,N*N){
      cout << ans[i];
      cout << (i==N*N-1? "\n":" ");
    }
  }else{
    cout << "No" << endl;
  }
  return 0;
}
