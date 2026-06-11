#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, s; cin >> k >> s;

    int ans = 0;
    for(int x=0; x<=k; x++){
        for(int y=0; y<=k; y++){
            if(x+y <= s && (s-x-y)<=k)
                ans++ ;
        }
    }
    cout << ans << endl;
    return 0;
}