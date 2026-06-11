#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int su=0;
  vector<int>t(n);
  for(int i=0;i<n;i++){
    cin >> t.at(i);
    su+=t.at(i);
  }
  int m,a,b;
  cin >> m;
  vector<int>yaku(m);
  for(int i=0;i<m;i++){
    cin >> a >> b;
    yaku.at(i)=t.at(a-1)-b;
  }
  for(int i=0;i<m;i++)
    cout << su-yaku.at(i) << endl;
  exit(0);
}