#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <climits>

using namespace std;
#define ll long long
#define ve vector
#define umap unordered_map
#define iter iterator

// const int MxN=1e5+1;
const ll MOD=1e9+7;
umap<int,int> mp;

int solve(int n) {
	ll ans = 1;
    int i=1;
	if(n%2) {
        i=2;
        if(mp[0] != 1) return 0;
    }
    for (i; i<n; i+=2) {
        if(mp[i] != 2) return 0;
        ans = ans*2 % MOD;
    }
    return ans;
}

int main() {
    int n; cin>>n;
    for(int i=0;i<n;i++) {
        int x; cin>>x;
        mp[x]++;
    }
    cout<<solve(n)<<endl;
    
    return 0;
}