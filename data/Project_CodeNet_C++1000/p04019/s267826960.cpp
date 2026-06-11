#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int cnt[5];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s = "NWSE";
    string t;
    cin >> t;
    for(int i = 0;i < t.length();i++){
        for(int j = 0;j < s.length();j++){
            if(t[i] == s[j]){
                cnt[j]++;
            }
        }
    }
    if((cnt[0] > 0) != (cnt[2] > 0)){
        cout << "No" << endl;
        return 0;
    }
    if((cnt[1] > 0) != (cnt[3] > 0)){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
