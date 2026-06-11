#include <bits/stdc++.h>

using namespace std;

int main(){
 int n,a,b; 
  cin >> n;
  
  int res=0;
  int rank=0;
  for(int i=0;i<n;i++){
  cin >> a >> b;
    if(a>rank){
   rank=a;
   res=a+b;
    }
    }
  cout << res << endl;
   
}