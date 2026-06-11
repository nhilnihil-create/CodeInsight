#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

bool check(string s,char f){
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] != f) return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    int ans = mod;
    set<char> st;
    for(int i = 0; i < (int)s.size(); i++) st.insert(s[i]);

    for(auto f:st){
        int can = 0;
        string now = s,nxt;
        int d = 0;

        if(check(now,f)){
            cout << 0 << endl;
            return 0;
        }

        while(true){
            can++;
            for(int i = 0; i < (int)now.size()-d-1; i++){
                if(now[i+1] == f) d = 1;
                else if(now[i] == f) d = 0;
                nxt.push_back(now[i+d]);
            }
            now = nxt;
            string emp;
            swap(emp,nxt);
            //cout << now << endl;
            if(check(now,f)){
                ans = min(ans,can);
                break;
            }
        }

    }
    cout << ans << endl;
    return 0;
}