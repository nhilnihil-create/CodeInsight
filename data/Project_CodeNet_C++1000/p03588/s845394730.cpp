#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n; cin >> n;
  long maxa=0, maxb=0;
  for(int i=0;i<n;i++){
    long a,b;
    cin >> a >> b;
    if(a>maxa){
      maxa = a;
      maxb = b;
    }
  }
  cout << maxa + maxb << endl;
    
}