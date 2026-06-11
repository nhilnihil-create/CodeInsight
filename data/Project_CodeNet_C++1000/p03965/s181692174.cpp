#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;


int main() {
        string s;
        cin >> s;
        int ans = 0;
        int cnt = 0;
        int n = s.size();
        rep(i,n){
                if(cnt == 0){
                        if(s[i] == 'g')cnt ++;
                        else {
                                cnt ++;
                                ans --;
                        }
                }
                else{
                        if(s[i] =='g'){
                                cnt --;
                                ans ++;
                        }
                        else{
                                cnt --;
                        }
                }
        }
        cout << ans << endl;
        return 0;
}