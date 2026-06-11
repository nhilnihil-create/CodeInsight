#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ll long long
#define BIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
int gcd(int a, int b){
    if(a%b == 0){
        return b;
    }else{
    return gcd(b, a%b);
    }
}

int main(){
    int n,k;
    ll sum=0;
    cin >> n >> k;
    vector<int> x(n);
    rep(i,n)
        cin >> x[i];
    rep(i,n){
        if(abs(k-x[i])<x[i]){
            sum+=2*abs(k-x[i]);
        }else
            sum+=2*x[i];
    }
    cout << sum << endl;
    return 0;
}