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


void solve() {
    int w,a,b;
    cin>>w>>a>>b;
    int x, y;
    if(a >= b && a <= b+w) cout<< 0;
    else if(b >= a && b <= a+w) cout<< 0;
    else cout<< min(abs(b-(w+a)),abs(a-(w+b))) <<endl;
}

int main() {
    solve();
    return 0;
}