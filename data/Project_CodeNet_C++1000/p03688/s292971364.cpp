#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int d = a[n-1]-a[0];
    if(d>1){
        cout << "No\n";
    }
    else if(d==0){
        if(n==a[0]+1 || n>=2*a[0]){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    else{
        int amtsmall = 0;
        while(amtsmall < n && a[amtsmall]==a[0]){
            ++amtsmall;
        }
        int amtbig = n-amtsmall;

        int small = a[0], big = a[n-1];

        if(amtsmall<=small && amtbig>=2*(big-amtsmall)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}