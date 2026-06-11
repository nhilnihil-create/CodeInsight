#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}


int main(){
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    int n = s.size();
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
    }

    char max_word;
    // for(auto x : mp){
    //     cout << x.first << endl;
    //     if(freq <= x.second){
    //         freq = x.second;
    //         max_word = x.first;
    //     }
    // }

    int ans = 105;
    for(auto &x : mp){
        //ある文字について，最大区間だけ変換が必要になる
        char word = x.first;
        int max_dist = 0;
        int r = 0;
        for(int l = 0; l < n; l++){
            while(r < n && s[r] != word){
                r++;
            }
            max_dist = max(max_dist, r-l);
            if(l == r) r++;
        }

        x.second = max_dist;
    }

    for(auto &x : mp){
        // cout << x.first << ", max: " << x.second << endl;
        ans = min(ans, x.second);
    }
    
    cout << ans << endl;
    return 0;
}
