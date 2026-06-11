#include <iostream>
using namespace std;
int main() {
    int h,w;
    string String[30][30];
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
               cin >> String[i][j];
        }
    }

    for (int k = 0; k < h; ++k) {
        for (int a = 0; a <w ; ++a) {
            if (String[k][a] == "snuke"){
                cout << (char)('A'+a)<< k+1 << endl;
                break;
            }
        }
    }
    return 0;
}