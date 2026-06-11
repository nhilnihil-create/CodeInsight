#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

string s;

int check(string s, char ch){
    int pre = 0;
    int ret = 0;
    for(int i = 0;i < s.length();i++){
        if(s[i] == ch){
            ret = max(ret, pre);
            pre = 0;
        }else{
            pre++;
        }
    }
    ret = max(ret, pre);
    return ret;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    int ans = s.length() - 1;
    for(char ch = 'a';ch <= 'z';ch++){
        int tmp = check(s, ch);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
