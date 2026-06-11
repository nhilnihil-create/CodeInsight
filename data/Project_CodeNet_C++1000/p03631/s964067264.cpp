#include<bits/stdc++.h>
using namespace std;
////////////////////
int main() {
    string N;
    cin >> N;
    // N = "575";
    string s(N.rbegin(), N.rend());
    
    if(N == s) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}