#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    int turn = 0;
    vector <string> p = {"First", "Second"};
    while(1){
        vector <int> cnt(2);
        for(auto &i : a) cnt[i % 2]++;
        if(cnt[1] == n) finish(p[turn ^ 1]);
        if(cnt[0] % 2) finish(p[turn]);
        if(cnt[1] >= 2) finish(p[turn ^ 1]);
        int g = 0;
        ll sum = 0;
        bool one = 0;
        for(auto &i : a){
            if(i % 2){
                if(i == 1) one = 1;
                else i--;
            }
            g = __gcd(g, i);
            sum += i;
        }
        if(one) finish(p[turn ^ 1 ^ ((sum - n) % 2)]);
        for(auto &i : a) i /= g;
        turn ^= 1;
    }
}
