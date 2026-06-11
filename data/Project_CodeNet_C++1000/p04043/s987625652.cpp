#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B >> C;

  int five = 0,sev = 0;

  if(A == 5){
    five++;
  } else if(A == 7){
    sev++;
  }
  if(B == 5){
    five++;
  } else if(B == 7){
    sev++;
  }
  if(C == 5){
    five++;
  } else if(C == 7){
    sev++;
  }
  if(five == 2 && sev == 1){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}

