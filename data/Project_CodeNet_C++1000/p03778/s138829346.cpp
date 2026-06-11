#include <bits/stdc++.h>
using namespace std;

int main(){
    long long w,a,b;
    cin >> w >> a >> b;
    long long x = abs(a-b) - w;
    cout << (abs(a-b) < w ? 0 : x) << endl;
}