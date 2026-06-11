#include <iostream>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;

int main()
{
  int a[3],five=0,seven=0;
  rep(i,3) cin >> a[i];
  rep(i,3){
    if(a[i]==5) five++;
    if(a[i]==7) seven++;
  }
  if(five==2 && seven==1)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}