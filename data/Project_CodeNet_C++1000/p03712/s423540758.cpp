#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  
  char A;
  for(int i=0;i<H+2;i++){
    for(int j=0;j<W+2;j++){
       if(i>0&&i<=H&&j>0&&j<=W){
    	  cin >> A;
          cout << A;
  		}
        else cout << "#";
    }
    cout << endl;
  }

}

