#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 51;
int main()
{
  int n,m,a,b,i;
  int c[N_MAX];
  cin >> n >> m;
  fill(c,c+n+1,0);
  for(i=0;i<m;i++){
    cin >> a >> b;
    c[a]++;
    c[b]++;
  }
  for(i=1;i<=n;i++)
    cout << c[i] << endl;
  return 0;
}