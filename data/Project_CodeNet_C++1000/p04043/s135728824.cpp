#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (A == 7){
		if(B == 5 && C == 5){
			cout << "YES" << endl;
        }
		else cout << "NO" << endl;
    }
	else if (A == 5){
		if(B == 7 && C == 5){
			cout << "YES" << endl;
        }
		else if(B == 5 && C == 7){
			cout << "YES" << endl;
        }
		else cout << "NO" << endl;
    }
}