#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {

    int h, w;
    cin >> h >> w;
    
    cout << std::string(w + 2, '#') << endl;
    string a = "";
    for (int i = 0; i < h; i++){
        cin >> a;
        cout << '#' << a << '#' << endl;
    }
    cout << std::string(w + 2, '#') << endl;
}