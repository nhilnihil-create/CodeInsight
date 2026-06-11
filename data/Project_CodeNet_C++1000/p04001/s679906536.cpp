#include <bits/stdc++.h>
// #include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);i++)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}
const ll inf = 1LL<<60;

int main(){
    string s;
    cin >> s;
    int n = s.length()-1;
    long long sum = 0;
 
    for(int bit = 0; bit < (1<<n);bit++){
        int start = 0;
        int stop = n+1;
        for(int i = 0;i < n;i++){
            if(1 & (bit>>i)){
                stop = i+1;
                sum += atoll(s.substr(start,stop-start).c_str());
                start = stop;
            }
        }
        sum += atoll(s.substr(start,n+1-start).c_str());
    }
    cout << sum << endl;
}