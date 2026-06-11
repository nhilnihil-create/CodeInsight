#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main (){
    string s;
    cin >> s;

    if(s[0] == s[2]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}