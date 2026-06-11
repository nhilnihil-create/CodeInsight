#include <bits/stdc++.h>
 
using namespace std;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int x = 0, y = 0, z = 0;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if(a % 2) x++;
        else if(a % 4 == 0) z++;
        else y++;
    }


    if(x <= z || (y == 0 && x <= z + 1)) cout << "Yes" << endl;
    else cout << "No" << endl;
}