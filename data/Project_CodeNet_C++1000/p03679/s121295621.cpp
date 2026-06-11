#include <bits/stdc++.h>
using namespace std;
int main(void){
    int X,A,B,C;
    cin >> X >> A >> B;
    C = X - A;
    if(C + B <= X) cout << "delicious" << endl;
    else if(X < C + B && C + B <= 2*X) cout << "safe" << endl;
    else cout << "dangerous" << endl;
}
