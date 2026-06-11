using namespace std;
#include <bits/stdc++.h>
#define rep(i, k, n) for(int i = k; i < (n); i++)
using ll = long long;

int main() {
    string a, b;
    cin >> a >> b;
    if (a.size() > b.size()) cout << "GREATER" << endl;
    else if (a.size() < b.size()) cout << "LESS" << endl;
    else{
        bool bigger = 0;
        int eq = 0;
        int length = a.size();
        for (int k = 0; k <= length; k++){
            int i = a[k] - '0';
            int j = b[k] - '0';
            if (i > j){
                bigger = 1;
                break;
            }
            else if (i < j){
                break;
            }
            else if (i == j) eq++;
        }

        if (bigger) cout << "GREATER" << endl;
        else if(eq == length + 1) cout << "EQUAL" << endl;
        else cout << "LESS" << endl;
    }
    return 0;
}