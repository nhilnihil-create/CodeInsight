#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

void solve() {
    string s;cin>>s;
    for(int i=0;i<s.length();i++) {
        if(i%2==0) cout<<s[i];
    }
}

int main() {
    solve();
    return 0;
}