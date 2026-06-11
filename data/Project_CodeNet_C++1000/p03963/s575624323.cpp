#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    int c=1;
    cin >> a;
    cin >> b;
    while(a>0){
        c = c*b;
        if (b/c==1){
            b--;
        }
        a--;
    }
    cout << c;
}
