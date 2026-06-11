#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    string s;
    cin >> s;
    stack<char> ans;
    rep(i, 0, s.size()){
        
        if(s[i] == 'B' && !ans.empty()){
            ans.top();
            ans.pop();
        }
        if(s[i] != 'B'){
            ans.push(s[i]);
        }
    }
    string anss= "";
    while(!ans.empty()) {
        char t = ans.top();
        anss+=t;
        ans.pop();
    }
    reverse(anss.begin(), anss.end());
    cout << anss << endl;
}
