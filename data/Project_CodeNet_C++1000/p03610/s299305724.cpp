#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;

int main(){
    string s;
    cin >> s;
    string ans;
    int n = s.size();
    for(int i=0;i<n;i=i+2){
        ans += s[i];
    }
    cout << ans << endl;
}