#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int k,s;
    int ans = 0;
    cin >> k >> s;
    for(int x=0;x<=k;x++){
        for(int y=0;y<=k&&y<=s-x;y++){
            if(s-x-y<=k) ans++;
        }
    }
    cout << ans << endl;
}