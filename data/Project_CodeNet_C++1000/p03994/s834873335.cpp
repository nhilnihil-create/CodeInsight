#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <numeric>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位
ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位

int main(void){
    string s;
    cin >> s;
    ll k;
    cin >> k;
    string al = "abcdefghijklmnopqrstuvwxyz";
    for(ll i = 0; i < s.length(); i++){
        if(s[i]=='a') continue;
        char a = s[i];
        ll b = 27-(a-96);
        //cout << k << " " << b << " " << a << endl;
        if(k >= b){
            s[i] = 'a';
            k-=b;
        }
    }
    //cout << k << endl;
    if(k!=0){
        ll check = k%26;
        char a = s[s.length()-1];
        //cout << check << endl;
        check = (check + a - 97)%26;
        //cout << check << endl;
        s[s.length()-1] = al[check];
    }
    cout << s << endl;
    return 0;
}
