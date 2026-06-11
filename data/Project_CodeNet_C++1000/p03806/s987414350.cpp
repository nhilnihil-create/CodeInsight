#include <iostream>
using namespace std;
const int MAX = 4001;
void chmin(int& x, int y) {if (x>y) x=y;}

int main() {
  int n; cin>>n;
  int m1,m2; cin>>m1>>m2;
  int a[n], b[n], c[n];
  for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
  int mn[401][401];
  fill(mn[0],mn[401],MAX);
  mn[0][0]=0;
  for(int i=0;i<n;i++) {
    for(int j=399;j>=0;j--) {
      for(int k=399;k>=0;k--) {
        if (j + a[i] <= 400 && k + b[i] <= 400) {
          chmin(mn[j+a[i]][k+b[i]],mn[j][k]+c[i]);
        }
      }
    }
  }
  int an = MAX;
  for(int i=m1, j=m2; i <= 400 && j <= 400; i+=m1, j+=m2) {
    chmin(an,mn[i][j]);
  }
  if (an == MAX) cout<<-1<<endl;
  else cout<<an<<endl;
}