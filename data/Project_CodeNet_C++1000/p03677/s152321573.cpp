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
vi removal[(int)3e5];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int n, m;cin >> n >> m;
    vi vals(n);
    FOR(i, n)cin >> vals[i];
    int cost = 0;
    vi updates(2*m);
    int begin = 0;
    FOR(i, n - 1){
        int nex = vals[i+1];
        int cur = vals[i];
        if(cur <= nex){
            if(nex- cur == 0)continue;
            cost += nex -cur;
            updates[cur+2]++;
            updates[nex + 1]--;
            removal[nex +1].pb(nex- cur- 1);
        }else{
            cost += (m - cur) + (nex - 1) + 1; 
            // no need to remove this last update
            // it will last till the end
            updates[cur+2]++;
            updates[1]++;
            begin += (m - cur) - 1;
            updates[nex + 1]--;
            removal[nex + 1].pb((m - cur) + (nex - 1) +1 -1);
        }

    }
    begin = -begin;
    int points = 0;
    int mn = 0;
    FOR1(i, m){
        points += updates[i]; 
        for(int r: removal[i])begin += r;
        begin -= points;
        mn = min(begin, mn);
    }
    cout<< cost +  mn << endl;
}


