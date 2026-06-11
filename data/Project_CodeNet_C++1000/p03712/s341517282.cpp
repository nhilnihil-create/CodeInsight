#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
/*
time:
wa:
反省:
考察:
*/
int main() {
    int h, w;
    cin >> h >> w;
    char c;
    string a[110];
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++){
            cin >> c;
            a[i] += c;
        }
    }
    
    for(int i = 0; i < h; i++){
        a[i].append("#");
        a[i].insert(0, "#");
    }
    for(int i = 0; i <= w+1; i++) cout << "#";
    cout << endl;
    for(int i = 0; i < h; i++) {
        cout << a[i] << endl;
    }
    for(int i = 0; i <= w+1; i++) cout << "#";
    cout << endl;
    return 0;
}