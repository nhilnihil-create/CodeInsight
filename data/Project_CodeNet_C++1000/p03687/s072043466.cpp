#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

int main() {
    string s;cin >> s;
    vector<int> ans;

    for(int i = 0; i < 26; i++) {
        vector<bool> a(s.size(),false);
        bool x=false;
        for(int j = 0; j < s.size(); j++) {
            if(s[j]==(char)(i+97)) {
                a[j]=true;
                x=true;
            }
        }

        if(!x) continue;

        int p=0;
        while(1){
            bool y=true;
            for(int j = 0; j < a.size(); j++) {
                if(!a[j]) y=false;
            }

            if(y){
                ans.push_back(p);
                break;
            }

            for(int j = 0; j < a.size()-1; j++) {
                if(a[j+1]) a[j]=true;
            }
            a.pop_back();
            p++;            
        }        
    }
    sort(ans.begin(),ans.end());
    cout << ans[0] << endl;

    return 0;
}