#include <iostream>
using namespace std;

const char c[2][2] = {'R', 'Y',
                      'G', 'B'};

int n, m, d;

int main(){

    cin >> n >> m >> d;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){

            int x = i+j;
            int y = i-j + 500;

            x = (x/d) % 2;
            y = (y/d) % 2;

            cout << c[x][y];

        }
        cout << "\n";
    }

    return 0;

}