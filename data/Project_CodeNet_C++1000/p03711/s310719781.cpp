#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

int g(int a){
  switch(a){
    case 1:
      return 1;
    case 3:
      return 1;
    case 5:
      return 1;
    case 7:
      return 1;
    case 8:
      return 1;
    case 10:
      return 1;
    case 12:
      return 1;
    case 4:
      return 2;
    case 6:
      return 2;
    case 9:
      return 2;
    case 11:
      return 2;
    case 2:
      return 3;
  }
}

int main(){
  int x,y;
  cin >> x >> y;
  map<int,int> mp;
  mp[g(x)]++;
  mp[g(y)]++;
  if(mp.size() == 1) cout << "Yes" << endl;
  else cout << "No" << endl;
}