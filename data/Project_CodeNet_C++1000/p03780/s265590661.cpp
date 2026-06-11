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
vi vals;
int n, k;
bool check(int mid){
    //debug(mid);
    //debug(vals[mid]);
    bitset<5005> prev;
    bitset<5005> dp;
    prev[0] = 1;
    FOR(i, vals.size()){
        if(i == mid)continue;
       // FOR(i, 5){   cout << i << " " << prev[i] << endl;  }
 //       cout <<endl;
        dp |= (prev << vals[i]);
        dp |= prev;
        swap(dp, prev);
    }
    //for(int i = k - 1; i >= 0; i--)  cout << i << " " << prev[i] << endl;
   
    for(int i = k -1; i >= max(0LL, k - vals[mid]); i--){
        // is necessary 
//        cout << i << " " << prev[i] << endl;
        if(prev[i])return false;
    }
    return true;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n >> k;
    vals.resize(n);
    int sum = 0;
    FOR(i, n)cin >> vals[i], sum += vals[i];
    sort(vals.begin(), vals.end());
    int s = 0, e = vals.size() - 1;
    int ans = -1;
    while(s <= e){
        int mid = (s+e)/2;
        if(check(mid)){
            s = mid+1;
            ans = mid;
        }else{
            e = mid -1;
        }
    }
    cout << ans + 1;
}


