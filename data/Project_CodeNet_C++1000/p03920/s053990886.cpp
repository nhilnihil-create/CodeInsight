#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N;  cin >> N;
    ll left = 0, right = N+1;
    ll m = left + (right-left)/2;
    while(right-left>1){
        ll sum = m*(m+1)/2;
        if(sum>=N) right = m;
        else left = m;
        m = left + (right-left)/2;
    }
    
    int M = right;
    while(N>0){
        if(N>=M){
            cout << M << endl;
            N-=M;
        }
        M--;
    }
}

