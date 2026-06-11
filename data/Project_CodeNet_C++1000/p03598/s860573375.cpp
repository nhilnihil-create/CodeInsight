#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,K,s;
    cin >> N >> K;
    s = 0;
    for(int i = 0; i < N ; i++){
        int x,t;
        cin >> x;
        t = K-x;
        if(t<0){
            t *= -1;
        }
        if(t<x){
            s += 2*t;
        }
        else{
            s += 2*x;
        }
    }
    cout << s << endl;
}