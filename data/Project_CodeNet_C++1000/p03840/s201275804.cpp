#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main() {
    long long a,b,c,d,e,f,g,h;
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    if(!a||!d||!e) cout<<a/2*2+b+d/2*2+e/2*2;
    else cout<<a+b+d+e-(a%2!=d%2||d%2!=e%2);
    return 0;
}