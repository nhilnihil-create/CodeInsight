#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a[] = {1,3,5,7,8,10,12};
    int b[] = {4,6,9,11};
    int c[] = {2};

    int x, y;
    cin >> x >> y;
    for(int z : a){
        if(z == x) x = 1;
        if(z == y) y = 1;
    }
    for(int z : b){
        if(z == x) x = 4;
        if(z == y) y = 4;
    }
    for(int z : c){
        if(z == x) x = 2;
        if(z == y) y = 2;
    }
    if(x == y) cout << "Yes" << endl;
    else cout<< "No" << endl;
    
    return 0;
}