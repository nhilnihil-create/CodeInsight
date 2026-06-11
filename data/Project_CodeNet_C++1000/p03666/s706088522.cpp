#include<iostream>
using namespace std;
int n, a, b, c, d, i;
long long minim, maxim;
int main(){
    cin>> n >> a >> b >> c >> d;
    if(a > b){
        swap(a, b);
    }
    n--;
    for(i = 0; i <= n / 2; i++){
        minim = max(0LL, c * 1LL * (n - i) - d * 1LL * i);
        maxim = (n - i) * 1LL * d - i * 1LL * c;
        if(b - a >= minim && b - a <= maxim){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}
