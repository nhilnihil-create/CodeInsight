#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <tuple>

using namespace std;

int main()
{
    string s;
    cin >> s;

    // パー <= グー
    int p_cnt = 0, g_cnt = 0;
    for(int i=0; i<s.length(); ++i){
        if(s[i] == 'p'){
            p_cnt++;
        }
        else{
            g_cnt++;
        }
    }
    int ans;
    ans = (g_cnt - p_cnt)/2;

    cout << ans << endl;
    return 0;
}