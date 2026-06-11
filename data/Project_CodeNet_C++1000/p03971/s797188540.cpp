#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    string s;
    cin >> n >> a >> b;
    cin >> s;
    int currentPassed = 0;
    int overseaRank = 0;
    vector <string> ans(n,"");
    for(int i = 0; i < n; i++){
        switch(s[i]){
            case 'a':
                if(currentPassed<(a+b)){
                    ans[i]="Yes";
                    currentPassed++;
                }else{
                    ans[i]="No";
                }
                break;
            case 'b':
                overseaRank++;
                if( (currentPassed<(a+b)) &&
                    (overseaRank <= b )){
                        currentPassed++;
                        ans[i]="Yes";
                }else{
                    ans[i]="No";
                }
                break;
            case 'c':
                ans[i]="No";
                break;
            default :
                break;
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }

    return 0;
}