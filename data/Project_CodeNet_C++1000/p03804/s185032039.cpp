#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <climits>
using namespace std;
#define rep(i,l,r) for(int i=l;i<r;i++)
#define repb(i,r,l) for(int i=r;i>l;i--)
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

bool check(vector<string> a, vector<string> b, int x, int y) {
    for(int i=0;i<b.size();i++) {
        for(int j=0;j<b[0].size();j++) {
            if(a[i+x][j+y]!=b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<string> a(n), b(m);
    for(string& i:a) cin>>i;
    for(string& i:b) cin>>i;
    for(int i=0;i< n-m+1;i++) {
        for(int j=0;j< a[0].size()-b[0].size()+1;j++) {
            if(a[i][j]==b[0][0]) {
                if(check(a,b,i,j)) {
                    cout<<"Yes";
                    return;
                }
            }
        }
    }
    cout<<"No";
}

int main() {
    solve();
    return 0; 
}