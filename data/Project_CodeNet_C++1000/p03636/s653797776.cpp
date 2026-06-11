#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main(void){

    string s;
    cin >> s;

    cout << s[0] << s.length()-2 << s[s.length()-1] << "\n";

    return 0;
}
