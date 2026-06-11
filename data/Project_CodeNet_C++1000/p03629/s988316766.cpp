#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int n = s.length();
    bool c[256];
    for(int j=0;j<256;j++) c[j] = false;
    int count = 0;
    vector<int> v[256];
    for(int i=0;i<n;i++) v[s[i]].push_back(i);
    vector<int> k;
    for(int i=n-1;i>=0;i--){
        if(c[s[i]]==false){
            c[s[i]] = true; count++;
            if(count == 26){
                for(char j='a';j<='z';j++) c[j] = false;
                k.push_back(i);
                //cout << "Enter" << endl;
                count = 0;
            }
        }
    }
    if(k.size() == 0) for(char j='a';j<='z';j++) if(!c[j]){cout << j <<endl; return 0;} 
    for(char j='a';j<='z';j++) v[j].push_back(n);
    reverse(k.begin(), k.end());
    //for(auto i: k) cout << i << endl;
    int l = k.size() + 1;
    string a;
    int cur_pos = -1;
    k.push_back(n-1);
    for(int i=0;i<l;i++){
        for(char j='a'; j<='z'; j++){
            int next = upper_bound(v[j].begin(), v[j].end(), cur_pos) - v[j].begin();
            //cout << j << ":" << next << endl;
            if(v[j][next] >= k[i]){
                a.push_back(j);
                cur_pos = v[j][next];
                j = 'z';
            }
        }
    }
    cout << a << endl;
    return 0;
}