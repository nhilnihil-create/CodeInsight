#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int br = 0;
    vector<int> a(n), b(8);
    rep(i,n){
        cin >> a[i];
        if(a[i]/400 > 7) br ++;
        else b[a[i]/400] ++; 
    }
    int mi = 0;
    rep(i, 8){
        if(b[i]) mi ++;
    }
    if(mi == 0){
        cout << 1 << " " << br;
    }
    else{
        cout << mi << " " << mi+br;
    }
    return 0;
}