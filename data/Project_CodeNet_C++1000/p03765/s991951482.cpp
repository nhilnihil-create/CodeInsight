#include <iostream>
#include <vector>
#include <string>
using namespace std; typedef long long ll; const int INF=1e9; typedef pair<ll,ll> P; const ll mod=1e9+7;

int main() {
  string s,t; cin>>s>>t;
  int n=s.size(), m=t.size();
  int a[n], b[m];

  for(int i=0;i<n;i++) {
    if (s[i] == 'A') a[i]=1; else a[i]=2;
  }
  for(int i=1;i<n;i++) a[i]=a[i-1]+a[i];
  for(int i=0;i<m;i++) {
    if (t[i] == 'A') b[i]=1; else b[i]=2;
  }
  for(int i=1;i<m;i++) b[i]=b[i-1]+b[i];

  int q; cin>>q;
  for(int i=0;i<q;i++) {
    int d,f,g,h; cin>>d>>f>>g>>h; d--; f--; g--; h--;
    int x1=a[f]; if (d!=0) x1-=a[d-1];
    int x2=b[h]; if (g!=0) x2-=b[g-1];
    //cout<<x1<<" "<<x2<<" ";
    if (abs(x1-x2)%3 == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}
