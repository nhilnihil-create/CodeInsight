#include<iostream>
using namespace std;
int N_MAX = 200000;
int main()
{
  int n,i;
  int a[N_MAX];
  cin >> n;
  for(i=0;i<n;i++)
    cin >> a[i];
  for(i=n-1;i>=0;i-=2)
    cout << a[i] << " ";
  for(i=n%2;i<n-1;i+=2)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}