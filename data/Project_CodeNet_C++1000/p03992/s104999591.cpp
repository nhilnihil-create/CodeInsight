    #include<bits/stdc++.h>                                                                                               
     
    using namespace std;
     
    #define rep(i,n) for(int i=0;i<(n);++i)
    #define reps(i,n) for(int i=1;i<=(n);++i)
    #define all(x) (x).begin(),(x).end()
    #define int long long
    using pii = pair<int,int>;
    constexpr int INF  = 0x3f3f3f3f;
    constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
    signed main(){
        string s,a;
        cin >> s;
        rep(i,4){
            cout << s[i];
        }   
        cout << " ";
        for(int i=4;i <= 11;++i){
            cout << s[i];
        }   
        cout << '\n';
        return 0;   
    }