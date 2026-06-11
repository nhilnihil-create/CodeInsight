#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int n,i,a,res=0;
  int c[9];
  cin >> n;
  fill(c,c+9,0);
  for(i=0;i<n;i++){
    cin >> a;
    if(a<3200)
      c[a/400]++;
    else
      c[8]++;
  }
  for(i=0;i<8;i++)
    if(c[i]>0)
      res++;
  if(res==0){
    res=1;
    c[8]--;
  }
  cout << res << " " << res+c[8] << endl;
  return 0;
}