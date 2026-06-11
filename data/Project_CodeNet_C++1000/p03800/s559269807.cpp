#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    s += s[0];
    s += s[1];
    for (int i = 0; i < 4; i++) {
        vector<int> a(N+2); //0:sheep, 1:wolf
        a[0] = i%2;
        a[1] = i/2;
        for (int j = 2; j <= N+1; j++) {
            if (s[j-1] == 'o' && a[j-1] == 0) a[j] = a[j-2];
            else if (s[j-1] == 'o' && a[j-1] == 1) a[j] = 1 - a[j-2];
            else if (s[j-1] == 'x' && a[j-1] == 0) a[j] = 1 - a[j-2];
            else if (s[j-1] == 'x' && a[j-1] == 1) a[j] = a[j-2];
        }
        if (a[0] == a[N] && a[1] == a[N+1]) {
            for (int j = 0; j < N; j++) {
                cout << ((a[j] == 0) ? "S" : "W");
            }
            cout << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}