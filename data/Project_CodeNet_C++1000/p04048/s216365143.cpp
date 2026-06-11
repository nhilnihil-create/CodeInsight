#include<bits/stdc++.h>
using namespace std;
long long n, x;
int main(int argc, char const *argv[]) {
    cin >> n >> x;
    int f = 0;
    long long sum = n;
    n -= x;
    while(x){
        if(n%x==0)sum+=n*2-x;
        else sum += (n/x)*x*2;
        long long t = x;
        x = n%x;
        n = t;
    }
    cout << sum;
    return 0;
}
