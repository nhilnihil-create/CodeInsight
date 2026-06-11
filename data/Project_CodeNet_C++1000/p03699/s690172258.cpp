#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i =0;i < n;i++){
        cin >> s[i];
    }
    sort(s.begin(),s.end());
    int ans = 0;
    for(int i =0;i < n;i++){
        ans += s[i];
    }
    int count =0;
    if(ans%10 == 0){
        if(s[0] % 10 == 0){
          while(s[count] % 10 == 0){
            count++;
            if(count == n){
                ans = 0;
                break;
            }
          }
        }
          
        if(count != n){
            ans -= s[count];
        }        
    }
    cout << ans << endl;
}
