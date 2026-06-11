#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;

int main(){
    LL x, y;
    cin >> x >> y;
    if(abs(x-y) > 1)    cout << "Alice" << endl;
    else    cout << "Brown" << endl;
}