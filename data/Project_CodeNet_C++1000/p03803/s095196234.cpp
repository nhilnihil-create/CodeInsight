#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;


char rev(char x) {
    if(x == 'S') return 'W';
    else return 'S';
}

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    A--;
    B--;

    if(A == 0) A += 13;
    if(B == 0) B += 13;

    if(A < B) {
        cout << "Bob" << endl;
    } else if(A > B) {
        cout << "Alice" << endl;
    } else {
        cout << "Draw" << endl;
    }
}