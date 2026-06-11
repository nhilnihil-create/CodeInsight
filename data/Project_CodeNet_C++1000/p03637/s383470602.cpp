#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;cin>>n;
  int a=0,b=0,c=0;
  int an;
  rep(i,n) {
    cin>>an;
    if (an%4==0) a++;
    else if (an%4==2) b++;
    else c++;
  }
  if (a >= n/2) cout << "Yes";
  else if (c <= a) cout << "Yes";
  else cout<<"No";

}
