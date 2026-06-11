#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
#define int long long int
string s;
int jmp[(int)2e5 + 10][27] = {0};
int nex[(int)2e5 + 10] = {0};
int dp[(int)2e5 + 10] = {0};
bool vis[(int)2e5 + 10] = {0};
int sol(int i){
   if(i == -1)return 1;
   if(vis[i])return dp[i];
   vis[i] = true;
   int& minLen = dp[i];
   minLen = 1e9;
   FOR(j, 26){
       int ans = sol(jmp[i][j]);
       ans++;
       if(ans < minLen){
            nex[i] = j; 
            minLen = ans;
       }
   }
   return minLen;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> s;
    map<char, int> last;
    map<char, bool> found;
    for(int i = s.length() - 1; i >= 0; i--){
       FOR(j, 26){
           jmp[i][j] = !found[char('a' + j)] ? -1 : last[char('a' + j)];
       }
       found[s[i]] = true;
       last[s[i]] = i; 
    }
    int minLen = 1e9; char x;
    FOR(i, 26){
        if(found['a' + i]){
            int ans = sol(last['a' + i]);
            if(ans < minLen){
                minLen = ans;
                x = 'a' + i;
            }
        }else{
            cout << char('a' + i);
            return 0;
        }
    }
   // debug(minLen);
    int ind = last[x];
    cout<< s[ind];
    while(ind != -1){
        int j = nex[ind];
        cout << char('a' + j);
        ind = jmp[ind][j];
    }
   

}


