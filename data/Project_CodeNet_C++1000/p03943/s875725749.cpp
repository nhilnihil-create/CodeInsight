#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main() {
    
	int a, b, c;

	cin >> a;
	cin >> b;
	cin >> c;

	if(a+b == c || b+c == a || c+a == b){
		cout << "Yes" << endl;
	} else{
		cout << "No" << endl;
	}
    
    return 0;
}

