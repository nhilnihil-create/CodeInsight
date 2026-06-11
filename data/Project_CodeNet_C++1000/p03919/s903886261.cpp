#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    string m[100][100];
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            cin >> m[i][j];
        }
    }
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(m[i][j] == "snuke") {
                char c = 'A' + j - 1;
                cout << c << i << endl;
            }
        }
    }
    return 0;
}
