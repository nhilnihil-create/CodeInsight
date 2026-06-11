#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> per(n),che(m);

    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        per[i] = make_pair(a,b);
    }
    for(int i = 0; i < m; i++){
        int c,d;
        cin >> c >> d;
        che[i] = make_pair(c,d);
    }


    for(int i = 0; i < n; i++){
        int num,mn = mod;
        for(int j = 0; j < m; j++){
            int d = abs(per[i].first-che[j].first)+abs(per[i].second-che[j].second);
            if(d < mn){
                mn = d;
                num = j;
            }
        }
        cout << num+1 << endl;
    }


    return 0;
}