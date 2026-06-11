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
    int n;cin>>n;
    deque<int> q;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        if(i&1) {
            q.push_front(x);
        } else {
            q.push_back(x);
        }
    }
    if(n%2 ==0)
        while(!q.empty()) {
            cout<<q.front()<<" ";
            q.pop_front();
        }
    else
        while(!q.empty()) {
            cout<<q.back()<<" ";
            q.pop_back();
        }
}

int main() {
    solve();
    return 0;
}