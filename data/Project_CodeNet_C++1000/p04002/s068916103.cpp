#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int,int> P;

const int M = 1e9;
  
int h, w, n;
unordered_set<int> black, used;
int ans[10], C;

void check(P point){
  
  for(int i=-2;i<=2;i++){
    
    for(int j=-2;j<=2;j++){
      
      int y1 = point.first + i;
      int x1 = point.second + j;
      int y2 = y1 + 2;
      int x2 = x1 + 2;
      
      if( y1 < 0 || x1 < 0 || h <= y1 || w <= x1 ) continue;
      
      if( y2 < 0 || x2 < 0 || h <= y2 || w <= x2 ) continue;
      
      if( used.count( y1 * M + x1 ) ) continue;
      
      used.insert( y1 * M + x1 );
      
      int cnt = 0;
      
      for(int k=y1;k<=y2;k++){
	
	for(int l=x1;l<=x2;l++){
	  
	  if( black.count( k * M + l ) ) cnt++;
	  
	}
	
      }
      
      if( cnt == 0 ) continue;
      
      ans[cnt]++;
      
      C++;
      
    }
    
  }
  
}

int a[100005], b[100005];

signed main(){
  
  cin>>h>>w>>n;
  
  for(int i=0;i<n;i++){
    
    cin>>a[i]>>b[i];
    
    black.insert( (a[i]-1) * M + b[i]-1 );
    
  }
  
  for(int i=0;i<n;i++){
    
    check( P( a[i] - 1, b[i] - 1 ) );
    
  }
  
  cout<<(h-2)*(w-2)-C<<endl;
  
  for(int i=1;i<10;i++) cout<<ans[i]<<endl;
  
  return 0;
}
