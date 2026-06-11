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
  int N; cin >> N;
  int overnum = 0;
  set<int> s;
  int a;
  rep(i,N){
    cin >> a;
    if (a>=3200) overnum++;
    else s.insert(a/400);
  }

  int MIN, MAX;
  if (overnum==0) MIN = s.size(), MAX = s.size();
  else if (s.size()==0) MIN = 1, MAX = overnum;
  else MIN = s.size(), MAX = (int)s.size() + overnum;

  cout << MIN << " " << MAX << endl;

  // cout << fixed << setprecision(6);
  return 0;
}

