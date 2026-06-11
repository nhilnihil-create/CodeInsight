#include<bits/stdc++.h>
using namespace std;

int main(){
  int x, a, b;
  cin >> x >> a >> b;
  if(pow(x-a, 2)<pow(x-b, 2)){
    cout << "A" << endl;
  }
  else{
    cout << "B" << endl;
  }
}
