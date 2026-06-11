#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

typedef long long LL;

bool ask(LL n){
    cout << "? " << n << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if(s == "Y")
        return true;
    else
        return false;
}

LL power[15];

bool check(int mid, LL now, LL i){
    LL tmp = (now * 10 + mid) * power[i] + power[i] - 1;
    if(ask(tmp))
        return true;
    else
        return false;
}

int main(){
    power[0] = 1;
    for(int i = 1;i <= 15;i++){
        power[i] = power[i - 1] * 10LL;
    }
    LL now = 1;
    int digit = -1;
    for(int i = 1;i <= 12;i++){
        now *= 10;
        if(!ask(now)){
            digit = i;
            break;
        }
    }
    if(digit == -1){
        now = 0;
        for(int i = 1;i <= 12;i++){
            now = now * 10 + 9;
            if(ask(now)){
                digit = i;
                break;
            }
        }
    }
    now = 0;
    for(int i = digit;i >= 1;i--){
        int l, r;
        if(i == digit)
            l = 1, r = 9;
        else
            l = 0, r = 9;
        while(l < r){
            int mid = (l + r) / 2;
            if(check(mid, now, i)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        now = now * 10 + l;
    }
    cout << "! " << now << endl;
    fflush(stdout);
    return 0;
}
