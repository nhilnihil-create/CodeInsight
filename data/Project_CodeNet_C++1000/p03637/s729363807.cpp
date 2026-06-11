#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;

    int oddNum = 0;
    int fourModZeroNum = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a % 4 == 0) {
            fourModZeroNum++;
        }
        else if(a % 2 != 0) {
            oddNum++;
        }
    }
    if (n % 2== 0 && oddNum <= fourModZeroNum) cout << "Yes" << endl;    
    else if (n % 2 == 1 && oddNum <= fourModZeroNum + 1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}