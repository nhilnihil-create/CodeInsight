#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
int p[200010];
int a[200010],b[200010];
int main()
{
  cin >> n;
  rep(i,n) cin >> p[i];

  rep(i,n){
    int index = p[i] - 1;
    a[index] = index * n + (i+1);
    b[index] = (n-index-1) * n + (i+1); 
  }

  rep(i,n) cout << a[i] << " ";
  cout  << "\n";
  rep(i,n) cout << b[i] << " ";
  cout  << "\n";
  
  return 0;
}
