#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
    string s;
    cin >> s;
    bool f = false;
    int S=0,T = 0;
    int ans = s.size();
    for (int i = 0; i < s.size();i++){
        if (f){
            if (s[i] == 'T'){
                if (S > 0) ans -=2,S--;
                else f = false;
            }
            else{
                S++;
            }
        }
        else{
            if (s[i] == 'S') f = true,S++;
            else continue;
        } 
    }
    cout << ans << endl;
    
    
    return 0;
}