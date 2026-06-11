#include <iostream>
#include <vector>
using namespace std;


int main(void){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int t = 0;
    int ans = 0;
    for(int i = 0;i < n;i++){
        switch(s[i]){
            case 'I':
                t++;
                ans = max(ans,t);
                break;
            case 'D':
                t--;
                break;
            default:
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
