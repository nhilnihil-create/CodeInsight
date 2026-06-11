#include <bits/stdc++.h>
using namespace std;
#define N 200005

int n, sol, flag;
int a[N];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sol = 1;
    flag = 0;
    for(int i = 2; i <= n; i++) {
        if(!flag) {
            if(a[i] == a[i - 1]) flag = 0;
            if(a[i] < a[i - 1]) flag = -1;
            if(a[i] > a[i - 1]) flag = 1;
        } else if(flag == 1) {
            if(a[i] < a[i - 1]) {
                sol++;
                flag = 0;
            }
        } else if(flag == -1) {
            if(a[i] > a[i - 1]) {
                sol++;
                flag = 0;
            }
        }
    }
    cout << sol << "\n";
}