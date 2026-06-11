#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    long long p;
    /*
    a->b
    a->b   *2 1 1
    a->cc
    a->dd  *2 1 0
    aa->c
    bb->c  *1 0 1
    aa->cc *3
    bb->dd    0 0
    */
    p = 3;
    int i = 0;
    int b = 1;//一つ前の状態
    if(n == 1)cout << p << endl;
    else{
        //初期状態
        if(s[0] == s[1]){
            p = 6;
            b = 0;
            i += 2;
        }else{
            p = 3;
            b = 1;
            i++;  
        }
        while(i < n){
            if(i < n-1 && s[i] == s[i+1]){
                if(b == 0)p *= 3;
                else p *= 2;
                b = 0;
                i += 2;
            }else{
                if(b == 1)p *= 2;
                b = 1;
                i++;
            }
            p %= MOD;
        }
        cout << p << endl;
    }
    //cin >> n;
}