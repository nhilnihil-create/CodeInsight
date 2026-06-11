#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    map<char, int> cnt;
    rep(i,h)rep(j,w){
        char c;
        cin >> c;
        cnt[c]++;
    }
    int two = 0, fou = 0;
    for(auto p : cnt){
        int num = p.second;
        while(num > 1){
            if(num == 2 || num == 3){
                two++;
                break;
            }
            fou++;
            num -= 4;
        }
    }
    bool yes = true;
    int fou_need = (h/2) * (w/2);
    int two_need = ((h+1)/2) * ((w+1)/2) - fou_need;
    if(h%2 == 1 && w%2 == 1) two_need--;
    if(fou_need > fou) yes = false;
    else two += (fou - fou_need) * 2;
    if(two_need > two) yes = false;
    if(yes) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}