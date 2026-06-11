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

int main() {
    int n; cin >> n;
    ve<int> a(n);
    for(int& i:a) cin>>i;
    int m=INT_MAX;
    sort(a.begin(),a.end());
    if(a[0]==a[n-1]) { 
        cout<<0<<endl;
        return 0;
    }
    for(int i=a[0];i<a[n-1];i++) {
        int c=0;
        for(int j:a) {
            c+=(j-i)*(j-i);
        }
        m=min(m,c);
    }
    cout<<m<<endl;
}