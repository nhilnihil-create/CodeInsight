#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
#define Reve(a) reverse(a.begin(), a.end())
typedef long long ll;
const ll MOD = 1e9+7;

int main(){
  int x, y;
  cin >> x >> y;
  if(x==0&&y<0) cout << -y+1 << endl;
  else if(x==0) cout << y << endl;
  else if(y==0&&x>0) cout << x+1 << endl;
  else if(y==0) cout << -x << endl;
  else{ 
  int m1, m2, m3, m4, m;  
  
  if(x<=y) m1 = y-x;
  else m1 = 1000000005;
  
  if(x<0&&y<0&&x>y) m2 = 2+x-y;
  else if(x>0&&y>0&&x>y) m2 = 2+x-y;
  else m2 = 1000000005;
    
  if(x<0&&y>0){
    if(-x<y) m3 = x+y+1;
    else m3 = 1-x-y;
  }  
  else if(x>0&&y<0){
    if(x<-y) m3 = -x-y+1;
    else m3 = 1+x+y;
  }
  else m3 = 1000000005;  
    
  m4 = min(m1, m2);
  m = min(m3, m4);  
  cout << m << endl;
    
  }
}