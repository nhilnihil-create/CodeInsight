#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int cnt = 0, cnt_b = 0;
    rep(i, 0, s.size()){
        if(s[i] == 'c') cout << "No" << endl;
        else if(s[i] == 'a'){
            if(cnt + cnt_b < a + b){
                cout << "Yes" << endl;
                cnt++;
            }
            else cout << "No" << endl;
        }
        else{
            if(cnt + cnt_b < a + b && cnt_b < b){
                cout << "Yes" << endl;
                cnt_b++;
            }
            else cout << "No" << endl;
        }
    }
    return 0;
}
