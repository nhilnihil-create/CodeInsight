#include <bits/stdc++.h>
using namespace std;

int main(){
  int W,a,b;
  cin >> W >> a >> b;
  
  if(abs(a-b) <= W){
    cout << "0" << endl;
  }else if(b > a){ //bが右にある
    cout << b-(a+W) << endl; 
  }else{
	cout << abs((b+W)-a) << endl;
  }
}