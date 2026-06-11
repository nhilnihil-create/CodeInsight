#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
//stoi(s) : string→int stoll(s) :string→longlong  int→string to_string(i)
const double PI = acos(-1.0);
//小数点の表し方 cout << fixed << setprecision(5);

int main(){
    string s;
    cin >> s;
    int n = s.size();
    map<char,int> m;
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    if(m.size() == 1){
        cout << 0 << endl;
        return 0;
    }
    int ans = 200;
    for(char c = 'a';c<='z';c++){
        if(m[c] == 0)continue;
        int cnt = 0;
        map<char,int>ma;
        ma = m;
        string sc = s;
        while(ma.size() > 0){
            for(int i = 0;i<s.size()-1;i++){
                if(sc[i] == c || sc[i+1] == c){
                    sc[i] = c;
                }
            }
            sc.pop_back();
            //cout << sc << endl;
            ma.clear();
            for(int i=0;i<sc.size();i++){
                ma[sc[i]]++;
            }
            if(ma.size() == 1) break;
        }
        cnt = n - sc.size();
        ans = min(ans,cnt);
    }
    cout << ans << endl;
}