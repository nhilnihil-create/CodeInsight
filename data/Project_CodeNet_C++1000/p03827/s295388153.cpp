#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define int long long
using namespace std;

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

signed main() {

    string s;
    int Max = 0;
    int n;
    int x = 0;
    cin >> n >> s;
    for(int i = 0; i < n; i ++){
        if(s[i] == 'I') x ++;
        if(s[i] == 'D') x --;
        Max = max(x,Max);
    }
    cout << Max;
    return 0;
}