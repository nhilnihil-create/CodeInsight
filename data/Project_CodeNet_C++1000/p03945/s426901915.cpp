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
    string s;
    cin >> s;
    int N = (int)s.size();
    //コーナーケースの除去（すべて'W' or 'B'の場合）
    bool is = true;
    rep(i, N-1){
        if(s[i] != s[i+1]){
            is = false;
            break;
        }
    }
    if(is){
        cout << 0 << endl;
        return 0;
    }
    int cnt = 0; //挟まれている状態の黒の集合の個数
    rep(i, N){
        if(s[i] == 'B' && s[i-1] == 'W'){
            while(i < N && s[i] == 'B') i++;
            if(i != N) cnt++;
        }
    }
    cnt *= 2;
    if(s[0] == 'B') cnt++;
    if(s[N-1] == 'B') cnt++;
    cout << cnt << endl;
    return 0;
}