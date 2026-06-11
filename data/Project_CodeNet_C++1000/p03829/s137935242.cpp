#include <bits/stdc++.h>
using namespace std;

int main(){
  using lint= long long int;
  int N;
  lint MPwalk, MPtele;
  cin >> N >> MPwalk >> MPtele;

  lint ans= 0;
  lint from, to;
  cin >> from;
  for(int i=1; i<N; i++){
    cin >> to;
    ans+= min(MPtele, MPwalk*(to- from));
    from= to;
  }

  cout << ans << endl;
}