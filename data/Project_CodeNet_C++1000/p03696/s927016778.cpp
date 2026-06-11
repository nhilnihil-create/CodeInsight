#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXA 1001
#define MAXB 1001
#define MAXH 1000000001
#define MAXW 301
#define INF (1LL << 50)
#define MAXN 100001
#define MAXM 100001
#define MAXK 100002
#define MAXP 1000001
#define MOD 1000000007
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

string s;
int N;

int main(){
    cin >> N >> s;
    stack<char> ss;
    string ans = "";
    for(int i = s.length() - 1;i >= 0;i--){
        if(s[i] == '(' && !ss.empty() &&ss.top() == ')'){
            ss.pop();
        }else ss.push(s[i]);
    }


    while(!ss.empty() && ss.top() == ')'){
        ans += "(";
        ss.pop();
    }
    ans += s;
    while(!ss.empty()){
        ans += ")";
        ss.pop();
    }

    cout << ans << endl;

    return 0;
}