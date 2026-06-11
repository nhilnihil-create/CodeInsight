/**
*    author:  souzai32
*    created: 15.08.2020 17:20:33
**/

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
typedef long long ll;
using namespace std;

int main() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    int left=0, right=0;
    rep(i,n){
        if(s.at(i)=='(') left++;
        if(s.at(i)==')'){
            if(left) left--;
            else right++;
        }
    }
    string front,back;
    rep(i,right) front.push_back('(');
    rep(i,left) back.push_back(')');
    s=front+s+back;
    cout << s << endl;

    return 0;
}