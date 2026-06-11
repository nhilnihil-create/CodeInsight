#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string A, B;
    cin >> A >> B;
    
    int a = A.size();
    int b = B.size();

    if (a == b)
    {
        int now = a;
        for(int i = 0; i < now; i++) {
            if(A.at(i) > B.at(i)) {
                a = 3;
                b = 1;
                break;
            } else if(A.at(i) < B.at(i)) {
                a = 1;
                b = 3;
                break;
            }
        }
    }
    
    

    if (a > b)
    {
        cout << "GREATER" << endl;
    } else if (a < b) {
        cout << "LESS" << endl;
    } else {
        cout << "EQUAL" << endl;
    }
    
    

    return 0;
}