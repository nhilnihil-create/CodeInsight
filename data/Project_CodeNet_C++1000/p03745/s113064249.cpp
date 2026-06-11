#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() { 
    int n;
    cin >> n;
    int a[110000];
    rep(i, n) cin >> a[i];
    int flag = 0;
    int count = 0;
    rep(i, n - 1) {
        if(a[i] < a[i + 1]) {
            if(flag == 2) {
                count++;
                flag = 0;
            }
            else flag = 1;
        }
        else if(a[i] > a[i + 1]) {
            if(flag == 1) {
                count++;
                flag = 0;
            }
            else flag = 2;
        }
    }
    cout << count + 1 << endl;
}