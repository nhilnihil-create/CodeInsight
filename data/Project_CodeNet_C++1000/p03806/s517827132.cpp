#include <iostream>
#include <algorithm>

using namespace std;


int main(void) {
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;

    int table[401][401];
    for(int i=0; i<=400; i++) {
        for(int j=0; j<=400; j++) {
            table[i][j] = 1000000;
        }
    }
    table[0][0] = 0;

    while(N--) {
        int a, b, c;
        cin >> a >> b >> c;
        for(int i=400-a; i>=0; i--) {
            for(int j=400-b; j>=0; j--) {
                table[i+a][j+b] = min(table[i+a][j+b], table[i][j] + c);
            }
        }
    }

    int ans = 1000000;
    for(int i=1; i<=400; i++) {
        for(int j=1; j<=400; j++) {
            if(Ma*j == Mb*i) {
                ans = min(ans, table[i][j]);
            }
        }
    }

    if(ans == 1000000) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
