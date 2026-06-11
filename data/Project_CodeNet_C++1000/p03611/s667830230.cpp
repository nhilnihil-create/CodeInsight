#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i,0,n)
#define BFOR(bit,a,b) for(int bit = (a); bit < (1<<(b)); ++bit)
#define BREP(bit,n) BFOR(bit,0,n)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(100010,0);
  
  REP(i,n){
    int x;
    cin >> x;
    x++;
    a[x]++;
    a[x-1]++;
    a[x+1]++;
  }
  
  sort(a.begin(),a.end());
  
  cout << a[100009] << endl;

}