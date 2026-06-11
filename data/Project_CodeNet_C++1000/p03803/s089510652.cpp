#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int A, B;
    cin >> A >> B;
    string s;
    if(A == B) s = "Draw";
    else if(A == 1) s = "Alice";
    else if(B== 1) s="Bob";
    else if(A > B) s="Alice";
    else s = "Bob";
    cout << s << endl;
}
