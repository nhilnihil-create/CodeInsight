#include <bits/stdc++.h>

using ll=long long;
using namespace std;

#define rep_i(i, n) for (int i = 0; i < (n); ++i)
#define rep_ll(i, n) for (long long i = 0; i < (n); ++i)
#define r_rep_i(i, start, end) for (int i = (start); i < (end); ++i)
#define r_rep_ll(i, start, end) for (long long i = (start); i < (end); ++i)
#define debug_vi(v) copy((v).begin(), (v).end(), ostream_iterator<int>(cout, " "));
#define debug_vll(v) copy((v).begin(), (v).end(), ostream_iterator<long long>(cout, " "));
#define debug_vd(v) copy((v).begin(), (v).end(), ostream_iterator<double>(cout, " "));
#define sort_v(v) sort((v).begin(), (v).end()); //昇順
#define d_sort_vi(v) sort((v).begin(), (v).end(), greater<int>()); //降
#define d_sort_vll(v) sort((v).begin(), (v).end(), greater<long long>()); //降
#define d_sort_vd(v) sort((v).begin(), (v).end(), greater<double>()); //昇順
#define say(t) cout << (t) << endl;
#define sum_vi(v) accumulate((v).begin(), (v).end(), 0);
#define sum_vll(v)accumulate((v).begin(), (v).end(), 0LL);

ll gcd(ll a, ll b) { return b?gcd(b, a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a, b)*b;}

const int IINF=(1<<30);
const ll LLINF = 1LL<<60;

char BigAlphaToSmall(char a){
    if (a >= 65 && a <= 90){
        return a + 32;
    }
    return a;
}

char SmallAlphaToBig(char a){
    if (a >= 97 && a <= 122){
        return a - 32;
    }
    return a;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, a, b;cin >> n >> a >> b;
    string s;cin >> s;
    int count = 0;
    int count_b = 1;
    for (int i = 0; i < n; i++){
        if(s[i] == 'a'){
            if(count < a + b){
                say("Yes")
                count++;
            }else{
                say("No")
            }
            continue;
        }

        if(s[i] == 'b'){
            if(count < a + b && count_b <= b ){
                say("Yes")
                count++;
                count_b++;
            }else{
                say("No")
            }
            continue;
        }

        if(s[i] == 'c'){
            say("No")
            continue;
        }
    }
    
}