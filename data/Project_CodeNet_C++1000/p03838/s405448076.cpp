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
  int x, y; cin >> x >> y;
  int retval = abs(abs(x)-abs(y));
  if ((x>0&&y<0) || (x<0&&y>0)) retval++;
  else if ((x==0 || y==0) && y<x) retval++;
  else if (y<x) retval+=2;

  cout << retval << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}

