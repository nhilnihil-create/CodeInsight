#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<char,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string s;
    cin >> s;

    vector<int> v(26);
    for (char i = 'a'; i <= 'z'; ++i) {
        int cnt = 0, ans = 0;
        rep(j, s.size()){
            if(s[j] == i){
                ans = max(ans, cnt);
                cnt = 0;
            }else{
                cnt++;
            }
        }
        ans = max(ans, cnt);
        v[i-'a'] = ans;
    }

    sort(all(v));
    cout << v[0] << endl;



    return 0;
}