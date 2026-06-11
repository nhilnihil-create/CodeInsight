#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < 20; i++){
        if(n < (1 << (i + 1))) {
            cout << (1 << i) << "\n";
            break;
        }
    }
    return 0;
}
