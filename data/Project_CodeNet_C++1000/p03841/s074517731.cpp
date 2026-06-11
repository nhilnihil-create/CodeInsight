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

int ans[500*500 + 10] = {0};
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    vpii dis(n);
    FOR(i, n)cin >> dis[i].first, dis[i].second = i + 1;
    sort(dis.begin(), dis.end());
    int sum = 0;
    int top = 1;
    FOR(i, dis.size()){
        int val = dis[i].second;
        int pos = dis[i].first;
        ans[pos] = val;
        sum += val;
        if(pos < sum){
            cout << "No";
            return 0;
        }
        FOR(j, val - 1){
            while(ans[top] != 0)top++; 
            ans[top] = val;
        }
    }

//    FOR1(i, n*n)cout << ans[i] << " ";cout <<endl;

    FOR(i, dis.size()){
        int val = dis[i].second;
        while(ans[top] != 0)top++;
        if(top < dis[i].first){
            cout << "No";
            return 0;
        }
        FOR1(j, n - dis[i].second){
            while(ans[top] != 0)top++;
            ans[top] = val;
        }
    }
    cout << "Yes" << endl;
    FOR1(i, n*n){
        cout << ans[i] << " ";
    }

}


