#include <bits/stdc++.h>
using namespace std;

int main(){

    string N;
    cin >> N;
    int i = 0;
    int x,y;
  
    for(i=0; i<N.size(); i++){
      if(N[i]=='A'){
        x = i;
        break;
      }
    }

    for(i=x; i<N.size(); i++){
      if(N[i]=='Z'){
        y = i;
      }
    }
  
    cout << y-x+1 << endl;
}