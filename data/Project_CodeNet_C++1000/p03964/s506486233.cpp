#include <bits/stdc++.h>

using namespace std;


int main() {
    int n ; cin>>n;
    long long one = 1 , two = 1;
    for(;n--;){
        int a , b;
        cin>>a>>b;
        long long mx = max((one - 1 + a) / a ,(two - 1 + b) / b);
        one = mx * a;
        two = mx * b;
    }
    cout<<two + one<<"\n";
}