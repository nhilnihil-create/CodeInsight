typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    string s;
    std::cin >> s;
    
    for (int i = 0; i < n; i++) {
        s[i] = (s[i] == 'o' ? '0' : '1');
    }
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            string ans ="";
            
            ans += to_string(i)+to_string(j);
            
            for (int k = 2; k <= n; k++) {
                if(s[k-1] == '0' && ans[k-1] == '0'){
                    ans += ans[k-2];
                }
                if(s[k-1] != '0' && ans[k-1] == '0'){
                    ans += to_string(((ans[k-2]-'0')+1)%2);
                }
                if(s[k-1] == '0' && ans[k-1] != '0'){
                    ans += to_string(((ans[k-2]-'0')+1)%2);
                }
                if(s[k-1] != '0' && ans[k-1] != '0'){
                    ans += ans[k-2];
                }
            }
            
            string required;
            
            if((ans[0] == '0' && s[0] == '0')||(ans[0] != '0' && s[0] != '0')){
                required = ans[1];
            }else{
                required = to_string(((ans[1]-'0')+1)%2);
            }
            
            if(ans[0] == ans[n] && ans[n-1] == required[0]){
                for (int i = 0; i < n; i++) {
                    ans[i] = ans[i] == '0' ? 'S' : 'W';
                }
                ans.erase(n);
                std::cout << ans << std::endl;
                return 0;   
            }
        }
    }
    std::cout << -1 << std::endl;
    
}
