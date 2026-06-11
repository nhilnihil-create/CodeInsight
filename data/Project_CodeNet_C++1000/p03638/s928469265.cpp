#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> c;
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        for (int j=0; j<a; j++) c.push_back(i+1);
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cout << c[i*w + (i%2?(w-j-1):j)] << (j==w-1?'\n':' ');
        }
    }
}
