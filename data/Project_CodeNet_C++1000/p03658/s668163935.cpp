#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)


int main(){
    int n,k;
    string s;
    cin >> n >> k;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    sort(v.begin(),v.end());
    int ans=0;
    rep(i,k){
       ans+=v[n-1-i];
    }
    cout << ans << endl;
}

