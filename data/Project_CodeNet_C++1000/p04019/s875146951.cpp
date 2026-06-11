#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

int main() {
    string s;
    cin >> s;
    ll sc=0,nc=0,wc=0,ec=0;
    rep(i, 0, s.size()){
        switch (s[i]) {
            case 'S':
                sc++;
                break;
            case 'N':
                nc++;
                break;
            case 'W':
                wc++;
                break;
            case 'E':
                ec++;
                break;
            default:
                break;
        }
    }
    if(sc>=1 && nc>=1 && wc>=1 && ec>=1) {cout << "Yes" << endl;return 0;}
    if(sc>=1 && nc>=1 && wc==0 && ec==0) {cout << "Yes" << endl;return 0;}
    if(sc==0 && nc==0 && wc>=1 && ec>=1) {cout << "Yes" << endl;return 0;}
    cout << "No" << endl;
    return 0;
}
