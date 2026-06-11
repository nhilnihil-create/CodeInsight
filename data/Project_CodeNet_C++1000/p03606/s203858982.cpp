#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin>>N;
  
  for(int i=0;i<N;i++){
    int A ;
    int l,r ;
    cin>>l>>r;
    
    A =A + r - l + 1;
    if(i+1 ==N){
      cout<<A<<endl;
    }
  }
    
}
