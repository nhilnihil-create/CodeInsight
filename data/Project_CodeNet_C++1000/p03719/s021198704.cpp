#include <bits/stdc++.h>
#include <algorithm>
#include<string>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B, C;
    cin >> A >> B >> C;
    if (C >= A && C <= B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}