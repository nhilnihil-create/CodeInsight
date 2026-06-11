#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
using namespace std;
#define rep(i,l,r) for(int i=l;i<r;i++)
#define repb(i,r,l) for(int i=r;i>l;i--)
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

void solve() {
    ve<int> mp(26, 0);
    string s;
    cin>>s;
    for(char i:s) {
        mp[i-'a']++;
        if(mp[i-'a']>1) {
            cout<<"no\n";
            return;
        }
    }
    cout<<"yes\n";
}

int main() {
    solve();
    return 0;
}