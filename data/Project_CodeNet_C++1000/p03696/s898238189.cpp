#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int left = 0, right = 0;
    rep(i,n){
        if(s[i]=='('){
            right++;
        }else if(s[i]== ')'){
            left++;
            if(right>0)
                right--, left--;
        }

    }
    for (int i = 0; i < left; i++)
        cout << '(';
    cout << s;
    for (int i = 0; i < right;i++)
        cout << ')';
    cout << endl;
    return 0;
}