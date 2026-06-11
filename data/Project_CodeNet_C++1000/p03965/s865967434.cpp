#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int len = s.length();
    int gu = 0;
    int pa = 0;
    int ans = 0;

    for(int i = 0; i < len; i++){
        if(pa < gu){
            if(s[i] == 'g'){
                pa++;
                ans++;
            }else{
                pa++;
            }
        }else{
            if(s[i] == 'g'){
                gu++;
            }else{
                gu++;
                ans--;
            }
        }
    }

    cout << ans << endl;
}