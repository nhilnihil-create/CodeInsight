#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define repr(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = 1e9 + 100;
const long long LLINF = 2e18 + 129;
const long long MOD = 1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    s.push_back(s[0]);

    string ans = "";
    const string t = "SW";
    rep(i, 2){
        rep(j, 2){
            ans.push_back(t[i]);
            ans.push_back(t[j]);

            REP(k, 2, n + 2){
                if(ans[k - 1] == 'S'){
                    if(ans[k - 2] == 'S'){
                        if(s[k - 1] == 'o'){
                            ans.push_back('S');
                        }else{
                            ans.push_back('W');
                        }
                    }else{
                        if(s[k - 1] == 'o'){
                            ans.push_back('W');
                        }else{
                            ans.push_back('S');
                        }
                    }
                }else{
                    if(ans[k - 2] == 'S'){
                        if(s[k - 1] == 'o'){
                            ans.push_back('W');
                        }else{
                            ans.push_back('S');
                        }
                    }else{
                        if(s[k - 1] == 'o'){
                            ans.push_back('S');
                        }else{
                            ans.push_back('W');
                        }
                    }
                }
            }

            if(ans[0] == ans[n] && ans[1] == ans[n + 1]){
                ans.pop_back();
                ans.pop_back();
                cout << ans << endl;
                return 0;
            }

            ans.clear();
        }
    }

    cout << -1 << endl;

    return 0;
}