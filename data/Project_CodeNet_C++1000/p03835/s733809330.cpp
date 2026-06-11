#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

int main(){
    int k, s;
    cin >> k >> s;
    int cnt=0;
    for(int i=0; i<=k; ++i){
        for(int j=0; j<=k; ++j){
            int z = s-i-j;
            if(!(z<0 || z>k))
                cnt++;
        }
    }
    cout << cnt;
}