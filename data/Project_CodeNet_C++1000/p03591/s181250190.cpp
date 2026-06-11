#include <bits/stdc++.h>
using namespace std;

int dist(int x1, int x2, int y1, int y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main(){
    string s;
    cin >> s;
    cout << (s.substr(0, 4) == "YAKI" ? "Yes" : "No") << endl;
    return 0;
}