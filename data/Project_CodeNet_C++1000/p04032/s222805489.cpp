#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;

    int st = -1;
    int ed = -1;
    for(char c='a'; c<='z'; c++){
        int s_cnt = 0;
        int d_cnt = 0;
        rep(i, s.length()){
            if(s[i]==c){
                if(st < 0) {
                    st = i;
                    s_cnt = 1;
                    d_cnt = 0;
                }
                else {
                    s_cnt++;
                    if((i-st+1) < s_cnt*2){
                        ed = i;
                        break;
                    }
                }
            }
            else {
                d_cnt++;
                if(st >= 0) {
                    if(d_cnt > s_cnt) {
                        st = -1;
                    }
                }
            }
        }
        if(st >= 0 && ed >= 0) {
            ++st; ++ed;
            break;
        }
    }
    cout << st << " " << ed << endl;

    return 0;
}
