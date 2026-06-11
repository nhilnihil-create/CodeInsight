#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    string s, t;
    cin >> s >> t;
    vector<int> cumsums((int)s.size()+1), cumsumt((int)t.size()+1);
    for(int i=1;i<=(int)s.size();++i){
        cumsums[i] = cumsums[i-1] + (s[i-1] == 'A' ? 1 : 2);
    }
    for(int i=1;i<=(int)t.size();++i){
        cumsumt[i] = cumsumt[i-1] + (t[i-1] == 'A' ? 1 : 2);
    }
    int q;
    cin >> q;
    for(int i=0;i<q;++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = (cumsums[b] - cumsums[a-1]) % 3;
        int y = (cumsumt[d] - cumsumt[c-1]) % 3;
        cout << (x == y ? "YES" : "NO") << endl;
    }

    return 0;
}