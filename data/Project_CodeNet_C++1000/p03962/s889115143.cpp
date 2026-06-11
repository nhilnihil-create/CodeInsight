#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int a,b,c;
  std::cin >> a>>b>>c;

  if (a!=b && a!=c && b!=c){
    cout << "3" << endl;
  }
  else if (a==b && b==c) {
    /* code */cout << "1" << endl;
  }  
  else{
    cout << "2" << endl;
  }
  return 0;
}