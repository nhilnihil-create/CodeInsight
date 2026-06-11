#include <bits/stdc++.h>
using namespace std;

int d[10];

bool func(int x){
    while (x > 0){
        if (d[x%10]==1){
            return false;
        }
        x/=10;
    }
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,l;
    cin >> n >> k;
    for (int i=0; i<k; i++){
        cin >> l;
        d[l] = 1;
    }
    while (true) {
        if (func(n)){
            cout << n << endl;
            break;
        }
        else{
            n++;
        }
    }
}