#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    char op;
    cin >> A >> op >> B;

    if(op == '+') cout << A + B << endl;
    else cout << A - B << endl;
}