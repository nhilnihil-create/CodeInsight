#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)

int gcd(int p,int q){
    if(p%q == 0){
        return q;
    }
        return gcd(q,p%q);
}

int main(){
    int n; cin >> n;
    int m = 1000000;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }

    int sum;
    for(int i=-100;i<=100;i++){
        int sum = 0;
        rep(j,n){
            sum += (i-a[j])*(i-a[j]);
        }
        m = min(m,sum);
    }

    cout << m << endl;
}
