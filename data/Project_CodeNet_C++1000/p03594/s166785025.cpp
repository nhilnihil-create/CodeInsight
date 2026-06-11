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
int dis(int r1, int c1, int r2, int c2){
    return abs(r1 - r2) + abs(c1 - c2);
}
char grid[501][501];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int h, w;cin >> h >> w;
    int d;cin >> d;
    //FOR(i, h)FOR(j, w)cin >> grid[i][j];
    FOR(i, h){
        FOR(j, w){
            int r = i + j;
            r /= d;
            int c = i - j + 500;
            c /= d;

            //cout << i << " " << j << endl;
//            cout << r << " " << c << endl;
            if((c & 1) && (r & 1)){
                cout << "R"; 
            }else if(c & 1){
                cout << "G"; 
            }else if(r & 1){
                cout << "B"; 
            }else{
                cout << "Y"; 
            }
        }
        cout << endl;
    }
}


