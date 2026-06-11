#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define ll long long
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int>>
const  long double eps = 1e-2;
const long double pi = acos(-1.0);
using namespace std;


ll get(int mask, string s){
    vector <int> pos;
    ll res = 0;
    for (int i = 0; i < 10; i++) if (mask & (1 << i)) pos.pb(i);
    pos.pb(s.length() - 1);
    string st = "";
    int ind = 0;
    for (int i = 0; i < s.length(); i++){
        st.pb(s[i]);
        if (i == pos[ind]){
            ind++;
            res += atoll(st.c_str());
            st = "";
        }
    }
    return res;
}

void solve(){   
    string s;
    cin >> s;
    int n = s.length() - 1;
    ll ch = 0;
    for (int mask = 0; mask < (1 << n); mask++){
        ll res = get(mask, s);
        ch += res;
        
    }    
    cout << ch << endl;
}
int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(3);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int step;
    step = 1;
    //cin >> step;
  for (int i = 1; i <= step; i++){
         solve();
    }
}
