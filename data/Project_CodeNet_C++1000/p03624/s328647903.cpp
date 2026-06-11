#include<bits/stdc++.h>
using namespace std;
 
int main() {
  string N;
  cin>>N;
  char c = 'a';
  int i,j;

  sort(N.begin(), N.end());

  for (i=0;i<N.size();i++){
    if(N[i]==c){
      c += 1; 
    }
  }

  if(c>'z'){
    cout << "None" << endl;
  }else{
    cout << c << endl;
  }
  //reverse(a,a+N);
  
  //cout << ans << endl;
}