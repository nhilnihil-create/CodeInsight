#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int h, w;
    cin >> h >> w;

    map<int, int> mp;
    for(int i=0; i<26; i++){
        mp[i] = 0;
    }
    for(int i=0; i<h*w; i++){
        char a;
        cin >> a;
        mp[a-'a']++;
    }

    int one = (h%2) * (w%2);
    int two = h * (w%2) + w * (h%2) - 2*one;
    int four = h*w - two - one;

    for(int i=0; i<26; i++){
        four -= mp[i] / 4 * 4;
        if(mp[i] % 4 != 0){
            if(mp[i] % 2 == 0) two -= 2;
            else if(mp[i] % 4 == 1) one--;
            else{
                two -= 2;
                one--;
            }
        }
    }
    if(four == 0 && two == 0 && one == 0) cout << "Yes" << endl;
    else if(two > 0 && four + two == 0 && one == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}