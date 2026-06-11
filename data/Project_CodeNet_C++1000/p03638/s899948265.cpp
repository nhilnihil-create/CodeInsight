#include<iostream>
using namespace std;
int N_MAX = 100;
int main()
{
  int h,w,n,i,j,k=0,t=0;
  int res[N_MAX];
  cin >> h >> w >> n;
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(t==0){
        cin >> t;
        k++;
      }
      res[j]=k;
      t--;
    }
    if(i%2==0){
      for(j=0;j<w;j++)
        cout << res[j] << " ";
    }else{
      for(j=w-1;j>=0;j--)
        cout << res[j] << " ";
    }
    cout << endl;
  }
  return 0;
}