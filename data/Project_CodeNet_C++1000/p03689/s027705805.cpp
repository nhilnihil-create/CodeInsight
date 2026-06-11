#include <iostream>
using namespace std;

int main(){
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  int a=(n/x)*(m/y);
  int b=n*m-a;
  if(n%x==0&&m%y==0){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
    int c=1e9;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(i%x==0&&j%y==0){
          cout << -c;
        }
        else{
          cout << (c-1)/(x*y-1);
        }
        cout << " ";
      }
      cout << endl;
    }
  }
}
