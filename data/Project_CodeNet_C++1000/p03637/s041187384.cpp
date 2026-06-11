#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int n,a,i;
  int f[3];
  fill(f,f+3,0);
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a;
    if(a%4==0)
      f[2]++;
    else if(a%2==0)
      f[1]++;
    else
      f[0]++;
  }
  if(f[2]>=f[0] || f[2]==f[0]-1&&f[1]==0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}