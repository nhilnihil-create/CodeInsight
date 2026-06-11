#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    string s;
    cin >> s;

    vector<char> chars((int)s.size());

    REP(i,(int)s.size()){
        chars[i] = s[i];
    }

    set<char> set_char(chars.begin(), chars.end());

    int ans = (int)s.size();
    for(auto itr=set_char.begin(); itr!=set_char.end(); itr++){
        int count = 0;
        char target = *itr;
        string tmp_s = s;

        while(true){
            bool is_equal = true;
            REP(i,(int)s.size()-count){
                if(tmp_s[i] != tmp_s[0]){
                    is_equal = false;
                    break;
                }
            }

            if(is_equal)break;

            string _s = "";
            REP(i,(int)s.size()-count-1){
                if(tmp_s[i] == target || tmp_s[i+1]== target){
                    _s += target;
                }else{
                    _s += tmp_s[i+1];
                }
            }

            tmp_s = _s;
            count++;
        }

        if(ans > count)ans=count;
    }

    cout << ans << endl;
    return 0;

    

}