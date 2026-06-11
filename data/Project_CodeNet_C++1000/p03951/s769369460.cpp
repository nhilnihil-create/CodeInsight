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
    int n;
    string s, t;
    cin >> n >> s >> t;
    
    int match = 0;
    bool all_match = true;
    for(int i = 0; i < n; i++){
        int sub = 0;
        if(s[i] == t[0]){
            string s_sub = s.substr(i, n);
            sub = s_sub.size();

            // cout << "substring\n";
            // cout << "s: " << s_sub << " t: " << t.substr(0, sub) << endl;
            if(s_sub == t.substr(0, sub)){
                match = max(match, sub);
            }
        }
    }
    
    cout << 2*n-match << endl;
    return 0;
}
