#include <bits/stdc++.h>
using namespace std;


void solve(){
  int k,s,x,y,z;
  int count=0;
  scanf("%d %d",&k,&s);
  for (int i = 0; i <= k; i++)
  {
    for (int j = 0; j <= k; j++)
    {
      
      if(s-i-j<=k && i+j<=s)count++;      
    }
    
  }
  

  printf("%d\n",count);
}
int main(){
  /*
  int q;
  scanf("%d",&q);
 le();
  */
  solve();

  return 0;
}