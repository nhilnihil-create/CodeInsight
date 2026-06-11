#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,k;
    cin >> n >> k;
    map<int,bool> mp;
    for(int i = 0; i < k; i++){
        int d;
        cin >> d;
        mp[d] = true;
    }

    for(int i = n; i < 1e6+1; i++){
        string s = to_string(i);
        bool end = true;
        for(auto p:s){
            if(mp[p-'0']){
                end = false;
                break;
            } 
        }
        if(end){
            cout << i << endl;
            break;
        }
    }
    return 0;
}