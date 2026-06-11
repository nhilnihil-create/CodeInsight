#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int k;
    cin >> s >> k;
    int n=s.size();

    for(int i = 0; i < n; i++) {
        int cost=s[i]-'a';
        if(cost!=0) cost=26-cost;
        if(k<cost) continue;
        else{
            s[i]='a';
            k-=cost;
        }
    }
    s[n-1]+=k%26;
    cout << s << "\n";

    return 0;
}