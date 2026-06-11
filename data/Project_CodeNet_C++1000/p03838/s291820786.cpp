#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int x, y;
    cin >> x >> y;

    int ans = 0;

    if(abs(x) < abs(y)){
        if(0 <= x){
            ans = abs(y) - abs(x);
            if(y < 0)ans++;
        }else{
            ans = 1;
            ans += abs(y) - abs(x);
            if(y < 0)ans++;
        }
    }else if(abs(x) > abs(y)){
        if(x >= 0){
            ans = 1;
            ans += abs(x) - abs(y);
            if(y > 0)ans++;
        }else{
            ans += abs(x) - abs(y);
            if(y > 0)ans++;
        }
    }else{
        ans = 1;
    }


    cout << ans << endl;
    return 0;
}
 
 
