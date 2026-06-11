#include <bits/stdc++.h>
using namespace std;

int main(){
int x,y,n;
  cin >> x >> y >> n;
  vector<vector<int>> data(n,vector<int>(3));
  for(int i=0;i<n;i++){
  for(int j=0;j<3;j++){
    cin >> data[i][j];
  }
  }
  set<int> a,b,c,d;
  for(int i=0;i<n;i++){
  if(data[i][2]==1) a.insert(data[i][0]);
  if(data[i][2]==2) b.insert(data[i][0]);
  if(data[i][2]==3) c.insert(data[i][1]);
  if(data[i][2]==4) d.insert(data[i][1]); 
  }
  int minx;
   if(!a.empty()) minx=*rbegin(a);
   else       minx=0;
  int maxx;
  if(!b.empty())maxx=*begin(b);
  else          maxx=x;
  
  int miny;
  if(!c.empty())miny=*rbegin(c);
  else         miny=0;
  
  int maxy;
  if(!d.empty())maxy=*begin(d);
  else          maxy=y;
  
  int S;
  if(minx>=maxx) S=0;
  if(minx<maxx){
  if(miny>=maxy) {S=0;}
  if(miny<maxy)  {S=(maxx-minx)*(maxy-miny);}
  }
  
 
  cout << S << endl;
  return 0;
}