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
const int MxN = 101;
int ar[101];
void solve() {
    int n;cin>>n;
    int res=0;
    for(int i=0;i<n;i++) {
        cin >> ar[i];
        res += ar[i];
    }
    if(res%10 == 0) {
        sort(ar, ar+n);
        for(int i=0;i<n;i++) 
            if(ar[i]%10 != 0) {
                res -= ar[i];
                goto q;
            }
        res = 0;
    }
    q:
    cout<<res<<endl;
}

int main() {
    solve();
    return 0;
}