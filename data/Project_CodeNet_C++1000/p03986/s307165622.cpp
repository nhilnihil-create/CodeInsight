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
    int len = s.length();

    int s_cnt = 0;
    int cnt = 0;
    rep(i,len){
        if(s[i] == 'S'){
            s_cnt++;
        }else{
            if(s_cnt>0){
                cnt += 2;
                s_cnt--;
            }
        }
    }

    cout << len-cnt << endl;
    return 0;
}
