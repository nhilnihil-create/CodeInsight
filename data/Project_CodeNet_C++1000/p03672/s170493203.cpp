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
    string s;cin>>s;
    for(int i=s.length()-2;i>=0;i--) {
        if(i&1) {
            int j;
            for(j=0;j<(i+1)/2;j++)
                if(s[j]!= s[(i+1)/2 +j]) break; 
            if(j >= (i+1)/2) {
                cout << i+1 << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}

int main() {
    solve();
    return 0;
}