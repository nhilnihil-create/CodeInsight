#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1001;
const int mod = 1e9 + 7;

using namespace std;

vector < int > make(string s)
{
        vector < int > v(26, 0);
        for(int i = 'a'; i <= 'z'; i++){
                int mask = 0, good = 0;
                for(char c: s){
                        if(c == i && !good){
                                good = 1;
                        } else if(good){
                                mask |= (1 << c - 'a');
                        }
                }
                v[i - 'a'] = mask;
        }
        return v;
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        string s;
        cin >> s;
        vector < int > a(26, 0);
        int cnt = 0;

        vector < vector < int > > v;

        string last = "";
        for(char c: s){
                int x = c - 'a';
                last += c;
                if(a[x] == 0){
                        a[x] += 1;
                        cnt += 1;
                        if(cnt == 26){
                                for(int i = 0; i < 26; i++){
                                        a[i] = 0;
                                }
                                cnt = 0;
                                v.push_back(make(last));
                                last = "";
                        }
                }
        }

        vector < int > d((int)v.size() + 1, 0);
        for(int i = 0; i < 26; i++){
                if(a[i] == 0){
                        d.back() |= (1 << i);
                }
        }
        for(int i = v.size() - 1; i >= 0; i--){
                for(int j = 0; j < 26; j++){
                        if(d[i + 1] != (d[i + 1] & v[i][j])){
                                d[i] |= (1 << j);
                        }
                }
        }
        string res = "";
        int blocked = 0;
        for(int i = 0; i <= v.size(); i++){
                for(int j = 0; j < 26; j++) if(!(blocked & (1 << j))){
                        if(d[i] & (1 << j)){
                                res += char('a' + j);
                                if(i < v.size()){
                                        blocked = v[i][j];
                                }
                                break;
                        }
                }
        }
        cout << res << "\n";
}
