#include <iostream>
#include <vector>

using namespace std;
#define ll long long

ll pos(ll a){
  if(a<0){
    return -a;
  }
  return a;
}

int main(void){
  ll a,b;
  cin >> a >> b;
  if(a>0){
    cout << "Positive" << endl;
  }else if(b >= 0){
    cout << "Zero" << endl;
  }else{
    if(pos(b - a) % 2 == 1){
      cout << "Positive" << endl;
    }else{
      cout << "Negative" << endl;
    }
  }
  return 0;
}