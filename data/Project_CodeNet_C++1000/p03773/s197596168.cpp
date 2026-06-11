#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

 
int main() {
	ll A,B;
  	cin >> A >> B;
  	if(A+B==24){
      cout << 0 << endl;
    }
  	else if(A+B>=24){
      cout << A+B-24 << endl;
    }
  	else{
      cout << A+B <<  endl;
    }
}
