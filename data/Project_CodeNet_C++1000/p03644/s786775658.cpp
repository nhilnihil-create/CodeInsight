#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9
 
int main() {

    int N;
    cin >> N;

    int ans =0;
    int count = 0;
    int max_count = 0;

    rep(i,N){
        int tmp = i+1;
        while(tmp%2 == 0){
            count++;
            tmp = tmp/2;
        }
        if(count > max_count){
            max_count = count;
            ans = i+1;
        }
        count = 0;
    }
    if(ans == 0){
        ans = 1;
    }

    cout << ans << endl;

    return 0;

}