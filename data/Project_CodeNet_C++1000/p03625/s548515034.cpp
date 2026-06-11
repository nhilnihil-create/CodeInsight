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
const int MxN = 1e5+1;
int ar[MxN];

void solve() {
    int n;cin>>n;
    for(int i=0;i<n;i++) {
        cin>>ar[i];
    }
    sort(ar, ar+n);
    int a=0,b=0;
    for(int i=n-2;i>=0;i--) {
        if(a==0) {
            if(ar[i]==ar[i+1]) {
                a=ar[i];
                i--;
            }
        } else if(b==0) {
            if(ar[i]==ar[i+1]) 
                b=ar[i];
        } else
            break;
    }
    cout << 1LL * a*b <<endl;
}

int main() {
    solve();
    return 0;
}