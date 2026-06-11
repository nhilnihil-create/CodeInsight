#include <bits/stdc++.h>
using namespace std;
long long n,m,h;
int main(void){
    scanf("%lld%lld", &n, &m);
    cout<<min(n,m/2)+max(m-n*2,h)/4;
} 