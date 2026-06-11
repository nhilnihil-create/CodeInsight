#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int N = S.size();
    vec<int> cnt(26);
    for(auto& c:S) cnt[c-'a']++;
    int ans = 1e9;

    auto check = [&](string T){
        int n = T.size();
        bool ok = true;
        for(int i=0;i+1<n;i++) ok &= T[i]==T[i+1];
        return ok;
    };

    for(int i=0;i<26;i++) if(cnt[i]){
        int now = 0;
        char c = 'a'+i;
        string T = S;
        while(!check(T)){
            int n = T.size();
            string A = "";
            for(int i=0;i+1<n;i++){
                if(c==T[i] || c==T[i+1]) A += c;
                else A += T[i];
            }
            T = A;
            now++;
        }
        ans = min(ans,now);
    }
    cout << ans << "\n";
}