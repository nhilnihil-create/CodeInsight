#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

long long e[7];

int main(){
    for(int i = 0; i < 7; i++){
        cin >> e[i];
    }
    long long a, b, c, d;
    a = e[0];
    b = e[1];
    c = e[3];
    d = e[4];
    long long ans = 0ll;
    ans += (a / 2ll) * 4ll;
    a %= 2ll;
    ans += b * 2ll;
    ans += (c / 2ll) * 4ll;
    c %= 2ll;
    ans += (d / 2ll) * 4ll;
    d %= 2ll;
    if(a + c + d == 3ll){
        ans += 6ll;
    }
    else if(a + c == 2ll){
        if(e[4] >= 2ll){
            ans += 2ll;
        }
    }
    else if(a + d == 2ll){
        if(e[3] >= 2ll){
            ans += 2ll;
        }
    }
    else if(c + d == 2ll){
        if(e[0] >= 2ll){
            ans += 2ll;
        }
    }
    cout << ans / 2 << endl;


    return 0;
}