#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,a,b;
pair<int,int> p[100005];

int main() {
  cin >> n;
  rep(i,n){
    cin >> a >> b;
    p[i]=make_pair(b,a);
  }
  sort(p,p+n);
  cout << p[0].first+p[0].second << endl;
}