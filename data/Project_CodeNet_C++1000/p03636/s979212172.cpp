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
    cout<<s[0]<<s.length()-2<<s[s.length()-1];
}

int main() {
    solve();
    return 0;
}