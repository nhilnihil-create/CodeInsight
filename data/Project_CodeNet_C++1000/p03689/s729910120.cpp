#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define db double
#define ll long long
const int INF = 1e9;
vector<int> solve(int x, int y){
    vector<int> res(x);
    for (int i=0;i<x;i++){
        if ((i%y) == y-1){
            res[i] = -INF;
        }
        if ((i%y) == ((x%y)-1)){
            res[i] = INF-1;
        }
    }
    return res;
}
main(){  
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a%c==0 && b%d==0){
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    if (b%d != 0){
        vector<int> res = solve(b, d);
        for (int i=0;i<a;i++){
            for (int j=0;j<b;j++) cout << res[j] << " ";
            cout << endl;
        }
        return 0;
    }
    vector<int> res = solve(a, c);
    for (int i=0; i < a; i++){
        for (int j=0;j<b;j++) cout << res[i] << " ";
        cout << endl;
    }
}