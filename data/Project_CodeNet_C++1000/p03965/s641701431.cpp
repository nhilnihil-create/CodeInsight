#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int p=0,ans=0;
    cin >> s;

    for(int i=0; i<s.size();i++){
        if (s[i]=='g' && p>=1){
            p -= 1;
            ans += 1;
        }
        else if (s[i]=='p'&& p>=1){
            p -= 1;
        }
        else if (s[i]=='g' && p==0){
            p+=1;
        }
        else if (s[i]=='p'&& p==0){
            ans -= 1;
            p += 1;
        }
        

        //cout << p << " " << ans << endl;

    }

    cout << ans << endl;



    return 0;
}