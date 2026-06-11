#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, t;
    cin >> k >> t;
    
    int max_a = 0;
    for(int i = 0; i < t; i++){
        int a;
        cin >> a;
        if(max_a < a) max_a = a;
    }

    if(k%2==1){
        if(max_a < k/2+2) cout << 0;
        else cout << 2*max_a-k-1;
    }
    else{
        if(max_a < k/2+1) cout << 0;
        else cout << 2*max_a-k-1;
    }
}