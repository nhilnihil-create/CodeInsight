#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int x,a,b;
    cin >> x >> a >> b;
    if(abs(x - a) > abs(x - b)) puts("B");
    else puts("A");
}