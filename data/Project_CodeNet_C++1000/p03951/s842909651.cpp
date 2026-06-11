#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){
    fast_io

    int n;
    string s, t;
    cin>>n>>s>>t;
    for(int i=0;i<n;i++){
        //cout<<"s.sustr(i)="<<s.substr(i)<<endl;
        //cout<<"t.substr(0, n-i)="<<t.substr(0, n-i)<<endl;
        if(s.substr(i) == t.substr(0, n-i)){
            cout<<i+n<<endl;
            return 0;
        }
    }
    cout<<2*n<<endl;

    return 0;
}