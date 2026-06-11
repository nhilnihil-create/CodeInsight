#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    ll q, h, s, d;
    cin >> q >> h >> s >> d;
    ll N;
    cin >> N;
    ll sum = 0;
    ll mn = min({q * 4, h * 2, s});
    ll mn_next;
    if(2 * mn > d){
        mn_next = mn;
        mn = d;
        if(N % 2 == 0){
            sum += mn * (N / 2);
        }else{
            sum += mn * (N / 2) + mn_next;
        }
    }else{
        sum += N * mn;
    }
    cout << sum << endl;
    return 0;
}