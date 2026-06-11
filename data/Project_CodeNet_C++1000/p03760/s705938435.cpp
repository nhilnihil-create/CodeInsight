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
const int MxN = 1e6+10;
char O[MxN],E[MxN];
void solve() {
    cin>>O>>E;
    for(int i=0;i<MxN;i++) {
        if(O[i]) cout<<O[i];
        if(E[i]) cout<<E[i];
    }
    cout<<endl;
}

int main() {
    solve();
    return 0;
}