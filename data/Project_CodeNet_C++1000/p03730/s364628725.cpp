#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    for (int i = 1; i < 10001; i++){
        if ((a*i)%b == c){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}