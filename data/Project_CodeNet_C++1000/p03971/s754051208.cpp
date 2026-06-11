#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define MOD 1000000007
#define endl "\n" 
#define rep(i,n) for(int i = 0; i < (n); ++i)
typedef long long ll;


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
  
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    int cnt = 0;
    int b_cnt = 0;
    rep(i, n) {
        if(s[i] == 'a' && cnt < a+b) {
            cout << "Yes" << endl;
            cnt++;
        } else if(s[i] == 'b' && cnt < a+b && b_cnt < b) {
            cout << "Yes" <<  endl;
            cnt++;
            b_cnt++;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
