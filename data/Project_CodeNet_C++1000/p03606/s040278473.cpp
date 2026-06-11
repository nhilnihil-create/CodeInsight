#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N,l,r,num,sum;

    cin >> N;
    sum = 0;

    rep(i,N){
        num = 0;
        cin >> l >> r;
        num = r - l + 1;
        sum += num;
    }
    cout << sum;
}