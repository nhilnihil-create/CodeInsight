# include <iostream>

using namespace std;

int main(){
    int a, b, c, d;
    int S1, S2;

    cin >> a >> b >> c >> d;

    S1 = a * b;
    S2 = c * d;

    if(S2 < S1){
        cout << S1 << endl;
    } else {
        cout << S2 << endl;
    }

    return 0;
}
