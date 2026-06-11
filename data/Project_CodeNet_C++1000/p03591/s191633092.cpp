#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  string a,b,c;
  cin >> a;
  
  if(a.length()<4){
  	cout << "No" <<endl;
    return 0;
  }
  if(a.substr(0,4)=="YAKI"){
  	cout << "Yes" <<endl;  
  }else{

  cout << "No" <<endl;
  }
  
   return 0;
}
