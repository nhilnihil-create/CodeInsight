#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int player = 0, point = -1;

    for (int i = 0; i < n; i++){
        int a, p;
        cin >> a >> p;
        if (player < a){
            player = a;
            point = p;
        }
    }
    player += point;
    cout << player << endl;
}