#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    string a,b;
    cin >> a >> b;
    
    if(a==b)cout << "EQUAL";
    
    else if(a.size()!=b.size())cout << ((a.size()>b.size())?"GREATER":"LESS");
    
    else{
        rep(i,a.size()){
            if(a[i]!=b[i]){
                cout << ((a[i]-'0'>b[i]-'0')?"GREATER":"LESS");
                return 0;
            }
        }
    }
    
    return 0;
}