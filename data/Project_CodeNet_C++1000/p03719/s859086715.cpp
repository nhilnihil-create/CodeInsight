#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define roop(i, n) for(int i = 0;i < n;i++)

int main(void){

    int a, b, c;
    cin >> a >> b >> c;
    
    if(a <= c && c <= b) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}