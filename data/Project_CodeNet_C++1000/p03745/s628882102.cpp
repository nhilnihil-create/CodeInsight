#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    int n;
    cin >> n;

    vi a(n);
    rep(i,n) cin >> a[i];
    string s;
    rep(i,n-1){
        if(a[i] > a[i+1])  s += '>'; //cout << ">";
        else if(a[i] < a[i+1])  s += '<';//cout << "<";
        //else s+="="; //cout << "=";
    }
    int ans = 1;
    if(s.length() == 0){
        cout << 1 << endl;
        return 0;

    }
    rep(i,s.length()-1){
        if(s[i] == '>' && s[i+1] == '<'){ans++;
            i++;
        }
        else if(s[i] == '<' && s[i+1] == '>'){ans++;
        i++;
        }
    }

    cout << ans << endl;
    return 0;
}