#include<iostream>
using namespace std;

int main() {
    string O, E; cin >> O >> E;
    for (int i = 0; i < E.size(); i++) {
        cout << O[i] << E[i];
    }
    if (O.size() > E.size()) {
        cout << O[O.size() - 1];
    }
    cout << endl;
}
