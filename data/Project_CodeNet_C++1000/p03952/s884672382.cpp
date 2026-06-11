#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){
    int n, x;
    cin >> n >> x;
    n = n*2-1;
    if(x==1||x==n) cout << "No\n";
    else{
        cout << "Yes\n";
        if(n==3){
            cout << "1\n2\n3\n";
            return;
        }
        vector<int> ans(n, -1);
        
        set<int> aval;
        for(int i = 1; i <= n; ++i) aval.insert(i);
        if(x==n-1){
            ans[n/2-2]=x-2;
            ans[n/2-1]=x+1;
            ans[n/2]=x;
            ans[n/2+1]=x-1;
            aval.erase(aval.find(x-2));
            aval.erase(aval.find(x+1));
            aval.erase(aval.find(x));
            aval.erase(aval.find(x-1));
        }
        else{
            ans[n/2-2]=x+2;
            ans[n/2-1]=x-1;
            ans[n/2]=x;
            ans[n/2+1]=x+1;
            aval.erase(aval.find(x+2));
            aval.erase(aval.find(x-1));
            aval.erase(aval.find(x));
            aval.erase(aval.find(x+1));
        }
        
        for(int i = 0; i < n; ++i){
            if(ans[i]==-1){
                ans[i] = *aval.begin();
                aval.erase(aval.begin());
            }
        }

        for(int i : ans) cout << i << '\n';
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}