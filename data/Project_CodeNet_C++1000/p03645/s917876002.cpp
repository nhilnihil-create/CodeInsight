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
    int n, m;
    cin >> n>> m;
    set<int> s1, s2;
    rep(i,m){
        int x, y;
        cin >> x >> y;
        if(x==1){
            s1.insert(y);
        }
        else if(y == 1){
            s1.insert(x);
        }
        else if(x == n){
            s2.insert(y);
        }
        else if(y == n){
            s2.insert(x);
        }
    }
    for(auto it : s1){
        if(s2.count(it)){
            cout << "POSSIBLE";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    
    return 0;
}
