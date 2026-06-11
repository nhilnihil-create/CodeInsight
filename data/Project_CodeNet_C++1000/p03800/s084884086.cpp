//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
string S;

string ans = "-1";

void solve(){
    string cand[4];
    if(S[0]=='o'){
        cand[0] = "SSS";
        cand[1] = "SWW";
        cand[2] = "WSW";
        cand[3] = "WWS";
    }
    if(S[0]=='x'){
        cand[0] = "SSW";
        cand[1] = "SWS";
        cand[2] = "WSS";
        cand[3] = "WWW";
    }
    for(int i=1;i<=N-1;i++){
        for(int j=0;j<4;j++){
            if(S[i]=='o'){
                //i番目を羊と決めたなら
                if(cand[j][i+1]=='S') cand[j] += cand[j][i];
                //i番目を狼と決めたなら
                if(cand[j][i+1]=='W'){
                    if(cand[j][i]=='W') cand[j] += 'S';
                    if(cand[j][i]=='S') cand[j] += 'W';
                }
            }
            if(S[i]=='x'){
                //i番目を羊と決めたなら
                if(cand[j][i+1]=='W') cand[j] += cand[j][i];
                //i番目を狼と決めたなら
                if(cand[j][i+1]=='S'){
                    if(cand[j][i]=='W') cand[j] += 'S';
                    if(cand[j][i]=='S') cand[j] += 'W';
                }
            }
        }
    }
    for(int j=0;j<4;j++){
        if(cand[j][0]==cand[j][N] && cand[j][1]==cand[j][N+1]){
            ans = "";
            for(int i=1;i<=N;i++) ans += cand[j][i];
            return;
        }
    }
}
 
int main(){
    cin >> N;
    cin >> S;
 
    solve();

    cout << ans << endl;
    return 0;
}