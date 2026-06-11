#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int w, a, b;
    cin >> w >> a >> b;
    if(abs(a - b) <= w){
        cout << 0 << endl;
    }else{
        cout << min(abs(a + w - b), abs(b + w - a)) << endl;
    }
}