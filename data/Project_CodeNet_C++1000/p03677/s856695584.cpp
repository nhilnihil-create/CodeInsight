#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

const int MAX_N = 100010;

int a[MAX_N];
int imos[3*MAX_N];

signed main(void){ 
  
  int n,m; cin >> n >> m;
  for(int i = 0; i < n; i++){ cin >> a[i];}
  
  int origin = 0; //お気に入りボタンがない時の、かかる操作回数を記録
  
  for(int i = 0; i < n-1; i++){ 
    int s = a[i]; int t = a[i+1];
    if( s > t ){ t += m;}
    origin += (t-s);
    imos[s+2]++; imos[t+1] -= (t-s); imos[t+2] += (t-s-1);
  }
  
  for(int k = 0; k < 2; k++){ 
    for(int i = 1; i < 3*MAX_N; i++){ 
      imos[i] += imos[i-1];
    }
  }
  
  int save = 0;
  
  for(int x = 0; x <= 2*MAX_N; x++){ 
    save = max( save, imos[x]+imos[x+m] );
  }
  
  cout << origin-save << endl;
  
  return 0;
} 
  