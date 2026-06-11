#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a,b;
    cin >> a >> b;
    if(a%3 == 0 || b%3 == 0 || (a+b)%3 == 0) puts("Possible");
    else puts("Impossible");
}