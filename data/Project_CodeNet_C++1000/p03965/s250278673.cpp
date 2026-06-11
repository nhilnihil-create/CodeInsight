#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int ans = 0;
    if(s[0] == 'p') ans--;
    int g = 1;
    for(int i=1; i<s.size(); i++){
        if(s[i] == 'p'){
            if(g > 0) g--;
            else{
                ans--;
                g++;
            }
        }
        else{
            if(g > 0){
                g--;
                ans++;
            }
            else g++;
        }
    }
    cout << ans << endl;
    return 0;
}
