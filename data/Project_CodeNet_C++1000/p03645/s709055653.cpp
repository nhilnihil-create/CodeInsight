#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 200000;
int main()
{
  int n,m,a,b,i,j=0;
  int c[N_MAX];
  cin >> n >> m;
  for(i=0;i<m;i++){
    cin >> a >> b;
    if(a==1){
      c[j]=b;
      j++;
    }
    if(b==n){
      c[j]=a;
      j++;
    }
  }
  sort(c,c+j);
  for(i=1;i<j;i++)
    if(c[i]==c[i-1]){
      cout << "POSSIBLE" << endl;
      return 0;
    }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}