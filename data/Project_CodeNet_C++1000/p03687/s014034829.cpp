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
    int len = (int)s.size();
    int mn = 10000;
    rep(j, len){
        char mx_char = s[j];
        int cnt = 0;
        string T = s;
        while(1){
            bool is = true;
            int size = (int)T.size();
            rep(i, size) if(T[i] != mx_char) is = false;
            if(is) break;
            cnt++;
            string t;
            rep(i, size-1){
                if(T[i] == mx_char || T[i+1] == mx_char){
                    t.push_back(mx_char);
                }else{
                    t.push_back(T[i+1]);
                }
            }
            T = t;
        }
        mn = min(mn, cnt);
    }
    cout << mn << endl;
    return 0;
}