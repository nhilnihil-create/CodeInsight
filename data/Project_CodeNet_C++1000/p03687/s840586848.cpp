#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define rad2deg(a) ((a)/M_PI * 180.0)
#define deg2rad(a) ((a)/180.0 * M_PI)
const std::string yes = "Yes";
const std::string no  = "No";

bool isSame(std::string s){
    for(int i=1; i<s.size(); i++){
        if(s[i]!=s[0]) return 1;
    }
    return 0;
}

int main(){
    std::string s;
    std::cin >> s;
    std::set<char> st;
    rep(i,s.size()) st.insert(s[i]);

    int ans = 1145141919;
    for(auto itr=st.begin(); itr!=st.end(); itr++){
        char a = *itr;
        std::string t = s;
        while(isSame(t)){
            std::string nt;
            rep(i,t.size()-1){
                if(t[i]==a || t[i+1]==a){nt+=a;}
                else{nt+=t[i];}
            }
            t = nt;
        }
        ans = std::min<int>(s.size()-t.size(),ans);
    }

    std::cout << ans << "\n";
    return 0;
}