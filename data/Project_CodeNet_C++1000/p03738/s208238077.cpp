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
    string a,b;
    cin>>a>>b;
    if(a.length() < b.length()) {
        cout<<"LESS \n";
        return;
    }
    if(a.length() > b.length()) {
        cout<<"GREATER \n";
        return;
    }
    for(int i=0;i<a.length();i++) {
        if(a[i]-'0' < b[i]-'0') {
            cout<<"LESS \n"; return;
        }
        if(a[i]-'0' > b[i]-'0') {
            cout<<"GREATER \n"; return;
        }
    }
    cout<<"EQUAL \n";
}

int main() {
    solve();
    return 0;
}