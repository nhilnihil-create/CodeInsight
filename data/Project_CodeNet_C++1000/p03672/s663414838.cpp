#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    string tmp="", left="", right="";
    int ans = 0;
    int n = s.length();
    for(int i=1; i<n; i++){
        tmp = s.substr(0, n-i);
        if(tmp.length()%2 != 0){
            continue;
        }else{
            int t_len = tmp.length();
            left = tmp.substr(0, t_len/2);
            right = tmp.substr(t_len/2, t_len/2);
            if(left == right){
                ans = t_len;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
    
}