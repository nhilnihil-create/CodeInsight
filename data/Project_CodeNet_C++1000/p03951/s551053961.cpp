#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int N;cin>>N;
    string s, t; cin >> s >> t;
    int ans=2*N;
    for(int i=N;i>=1;i--){
        if(s.substr(N-i,i) == t.substr(0,i)) {cout << ans-i << endl; break;}
        if(i==1) cout << ans << endl;
    }
}
