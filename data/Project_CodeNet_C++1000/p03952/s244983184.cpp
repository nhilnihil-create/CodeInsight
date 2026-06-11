#include <iostream>
using namespace std;
int main() {
  int n, k, i, j;
  cin>>n>>k;
  if(k>1 && k<2*n-1){
    cout<<"Yes\n";
    j=2;
    for(i=1; i<=2*n-1; i++){
      if(i==n-1)
        cout<<"1\n";
      else if(i==n)
        cout<<k<<"\n";
      else if(i==n+1)
        cout<<2*n-1<<"\n";
      else{
        if(j==k)
          j++;
        cout<<j<<"\n";
        j++;
      }
    }
  }else
    cout<<"No";
  return 0;
}
