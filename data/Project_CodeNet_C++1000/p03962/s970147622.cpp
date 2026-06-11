#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, O;
    cin >> N >> M >> O;
    if(N == M && M == O && N == O){
      cout << 1 << endl;
    }
    else if(N != M && M != O && N != O ){
        cout << 3 << endl;
    }
    else cout << 2 << endl;
}