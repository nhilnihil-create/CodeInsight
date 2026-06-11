#include <bits/stdc++.h>
using namespace std;

int main() {
    int W , a , b;
    cin >> W >> a >> b;
    int m = min(a , b) , t = max(a , b);
    if(W + m >= t){
        cout << 0 << endl;
    }
    else{
        cout << t - W - m << endl;
    }
}