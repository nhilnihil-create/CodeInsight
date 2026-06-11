#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;
const ll MOD = 1e9+7;

int main(){
    int h, w; cin >> h >> w;
    vector<int> data(26,0);
    rep(i,h){
        string s; cin >> s;
        rep(j,w) data[s[j]-'a']++;
    }
    vector<int> data2(4,0);
    rep(i,26){
        int k = data[i]%4;
        data2[k]++;
    }
    if(h%2==0 && w%2==0){
        cout << (data2[1]==0 && data2[2]==0 && data2[3]==0 ? "Yes" : "No") << endl;
    }
    else if(h%2==1 && w%2==0){
        if(!(data2[1]+data2[3] == 0)) cout << "No" << endl;
        else if(w/2>=data2[2] && (w/2-data[2])%2==0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if(h%2==0 && w%2==1){
        if(!(data2[1]+data2[3] == 0)) cout << "No" << endl;
        else if(h/2>=data2[2] && (h/2-data[2])%2==0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        if(!(data2[1]+data2[3] == 1)) cout << "No" << endl;
        else if(h+w-2>=(data2[2]+data2[3])*2 && (h+w-2-(data2[2]+data2[3])*2)%4==0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}