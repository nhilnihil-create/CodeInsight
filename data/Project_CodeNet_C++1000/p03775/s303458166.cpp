#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int c_digit(ll div){
    int cnt = 0;
    while(div != 0){
        div /= 10;
        cnt++;
    }
    return cnt;
}


int main(void){
    ll N;
    cin >> N;
    int tmp;
    int cnt = 20;
    for(ll i = 1 ; i * i <= N ; i++){
        
        if(N % i == 0){
            tmp = max(c_digit(i),c_digit(N/i));
        }
        if(tmp < cnt){
            cnt = tmp;
        }
    }
    
    cout << cnt << endl;
}
