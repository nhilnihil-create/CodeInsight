#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int A,B,C;
    cin >> A >> B >> C;

    if((C >= A) && (C <= B))
        cout << "Yes\n";
    else 
        cout << "No\n";
    return 0;
}
