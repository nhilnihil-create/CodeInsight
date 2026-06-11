#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    
    vector<string> strings(h);
    int maxLength = 0;
    
    for (int i=0; i<h; i++) {
        cin >> strings.at(i);
        maxLength = max(maxLength, int(strings.at(i).size()));
    }
    
    
    for (int i=0; i<maxLength+2; i++) {
        cout << "#";
    }
    cout << endl;
    
    for (int i=0; i<h; i++) {
        cout << "#" << strings.at(i) << "#" << endl;
    }


    for (int i=0; i<maxLength+2; i++) {
        cout << "#";
    }
    cout << endl;
}
