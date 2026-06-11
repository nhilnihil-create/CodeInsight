#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    string t;
    int ans = 999999;
    bool aaa = false;
    set<char>ss;
    for(int i=0;i<s.length();i++)ss.insert(s[i]);
    if(ss.size() == 1)cout << 0 << endl;
    else{
for(int i=0;i<26;i++){
        char c = (i+'a');
        bool chk = false;
        t = s;
        while(!chk){
            string u = "";
            chk = true;
            for(int j=0;j<t.length()-1;j++){
                if(t[j]==c || t[j+1]==c)u+=c;
                else {
                    u+='1';
                    chk = false;
                }
            }
            t = u;
        }
        if(ans > s.length()-t.length())ans = s.length()-t.length();
    }
    cout << ans << endl;
    }


    
}
