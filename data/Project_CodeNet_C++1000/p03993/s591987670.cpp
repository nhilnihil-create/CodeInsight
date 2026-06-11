#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i = 0;i < (n); ++i)
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
    int count = 0;

    rep(i,n){
        if(i+1 == a[a[i]-1]) count++;
    }
    
    cout << count/2 << endl;
    return 0;
}