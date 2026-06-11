#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

 
int main() {
	ll A,B,C;
  	cin >> A >> B >> C;
  	if(A==B && B==C){
      cout << "Yes" << endl;
    }
	else if(C>A && C<B){
      cout << "Yes" << endl;
    }
  	else{
      cout << "No" <<  endl;
    }
}
