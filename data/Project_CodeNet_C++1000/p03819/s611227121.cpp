#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vii         vector<pair<int,int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define endl '\n'
#define int long long int
using namespace std;
int tree[(int)2e5] = {0};
int MaxIdx;
int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}


void update(int idx, int val){
    while (idx <= MaxIdx){
        tree[idx] += val;
        idx += (idx & -idx);
    }
    //FOR1(i, 5)cout << tree[i] << " ";cout << endl;

}

int readSingle(int idx){
    int sum = tree[idx]; // this sum will be decreased
    if (idx > 0){ // the special case
        int z = idx - (idx & -idx);
        idx--; // idx is not important anymore, so instead y, you can use idx
        while (idx != z){ // at some iteration idx (y) will become z
            sum -= tree[idx]; 
// substruct tree frequency which is between y and "the same path"
            idx -= (idx & -idx);
        }
    }   
    return sum;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m;cin >> n>> m;
    MaxIdx = m;
    vii ranges(n);
    FOR(i, n){
        cin >> ranges[i].first >> ranges[i].second; 
    }
    sort(ranges.begin(), ranges.end(), [](pii& a, pii& b){return a.second - a.first > b.second - b.first;});
    vi sum(m + 1);
    for(int i = 1; i <=m ;i++){
        while(!ranges.empty() && ranges.back().second - ranges.back().first + 1 <= i){
            update(ranges.back().first, 1);
            update(ranges.back().second +1, -1);
            ranges.pop_back();
        }
        int ans = 0;
        for(int j = i; j <=m; j+= i){
            ans += read(j);
//            cout << ans << " ";
        } 
        ans += ranges.size();
        cout << ans << endl;
    }
}


