#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, a, b;
    cin >> x >> a >> b;
    
    if(b-a > x) puts("dangerous");
    else if(b-a > 0 && b-a <= x) puts("safe");
    else puts("delicious");
}