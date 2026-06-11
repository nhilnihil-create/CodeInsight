#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string s;
    cin >> s;
    int ans = 1 << 30;
    unordered_set<char> st; 
    for (int i=0; i<s.size(); i++){
        st.insert(s[i]);
    }
    if(st.size() == 1){
        cout << 0 << endl;
        return 0;
    }
    
    for (int i=0; i<26; i++){
        // cout << char('a' + i) << endl;
        char target = 'a' + i;
        string t = s;
        if(st.find(target) == st.end()){
            continue;
        }
       
        int tmp_cnt = 0;
        bool flag = false;
        while(!flag){
            flag = true;
            for (int i=0; i<t.size(); i++){
                if (t[i] != target) flag = false;
            }
            string tmp = "";
            for (int i=0; i<t.size()-1; i++){
                if(t[i] == target || t[i+1] == target){
                    tmp += target;
                }else{
                    tmp += s[i];
                }
            }
            t = tmp;
            tmp_cnt++;
        }
        ans = min(tmp_cnt, ans);
    }
    cout << ans - 1 << endl;
}
