#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int h,w;
    cin >> h >> w;
    char a;
    int cnt[26] = {};
    REP(i,h){
        REP(j,w){
            cin >> a;
            cnt[a - 'a']++;
        }
    }
    if(h == 1 || w == 1){
        bool odd = false;
        REP(i,26){
            if(cnt[i] % 2 == 1){
                if(odd){
                    cout << "No" << endl;
                    return 0;
                }
                odd = true;
            }
        }
        cout << "Yes" << endl;
    }else if(h % 2 == 0 && w % 2 == 0){
        REP(i,26){
            if(cnt[i] % 4 != 0){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }else if(h % 2 == 0 || w % 2 == 0){
        int even;
        if(h % 2 == 0) even = h;
        else even = w;
        int two = 0;
        REP(i,26){
            if(cnt[i] % 4 == 2){
                two++;
                if(two > even / 2){
                    cout << "No" << endl;
                    return 0;
                }
            }else if(cnt[i] % 4 != 0){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }else{
        int two = 0;
        bool odd = false;
        REP(i,26){
            if(cnt[i] % 4 == 2){
                two++;
                if(two > h / 2 + w / 2){
                    cout << "No" << endl;
                    return 0;
                }
            }else if(cnt[i] % 4 != 0){
                if(odd){
                    cout << "No" << endl;
                    return 0;
                }
                odd = true;
            }
        }
        cout << "Yes" << endl;
    }
    return 0;
}