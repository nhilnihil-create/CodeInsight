#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
int min_color = 0, max_color = 0;
vector<int> color(8, 1);

void count(int c) {
    if (color[c]) {
        min_color++;
        max_color++;
        color[c] = 0;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i,n){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    rep(i, n) {
        int c, a = A[i];
        if (a <= 399) {
            c = 0;
            count(c);
        } else if (a <= 799) {
            c = 1;
            count(c);

        } else if (a <= 1199) {
            c = 2;
            count(c);

        } else if (a <= 1599) {
            c = 3;
            count(c);

        } else if (a <= 1999) {
            c = 4;
            count(c);
        } else if (a <= 2399) {
            c = 5;
            count(c);
        } else if (a <= 2799) {
            c = 6;
            count(c);
        } else if (a <= 3199) {
            c = 7;
            count(c);
        }else{
            max_color++;
            if (min_color == 0) {
                min_color++;
            }
        }
    }
    cout << min_color << " " << max_color << endl;

    return 0;
}