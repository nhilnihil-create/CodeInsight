#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    rep(i,s.length() -1) {
        if(s[i] != s[i+1]){
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}