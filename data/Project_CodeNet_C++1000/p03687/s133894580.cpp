#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int ans = 100;// MAX
    for(int i=0; i<26; i++){
        char letter = 'a' + i;
        if(s.find(letter) == s.npos) continue;

        string t = s;
        int test = 0;
        while(1){
            string u = "";
            bool flag = true;

            for(int j=0; j+1<t.length(); j++){
                if(t[j]   == letter 
                || t[j+1] == letter) u += letter;
                else{
                    u += t[j];
                    flag = false;
                }
            }

            if(flag == true) break;
            t = u;
            test += 1;
        }
        if(test != 0) test += 1;
        ans = min(ans, test);
    }
    cout << ans << endl;
    return 0;
}