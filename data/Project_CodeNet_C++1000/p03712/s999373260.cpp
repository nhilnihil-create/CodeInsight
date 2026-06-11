#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> foo(h);

    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;

        string si;
        si.push_back('#');

        for (auto sii:s) {
            si.push_back(sii);
        }
        si.push_back('#');
        foo[i] = si;
    }

    for (int i = 0; i < w + 2; i++) {
        cout << '#';
    }

    cout << endl;


    for (auto si:foo) {
        cout << si << endl;
    }

    for (int i = 0; i < w + 2; i++) {
        cout << "#";
    }

    cout << endl;
}