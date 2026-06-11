#include <bits/stdc++.h>
using namespace std;

int main() {
	string op;
	int A , B ,C=0;
    cin >> A >> op >> B;
  
  if (op=="+"){
  	C = A + B;
  		}else{
    C = A - B;
		}
      cout << C << endl;
}