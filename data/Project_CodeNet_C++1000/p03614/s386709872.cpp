# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <cstring>
# include <stdio.h>
# include <map>
# include <queue>

# define ll long long
# define pii pair<int,int>
# define FOR(a,b) for(int a=1; a<=b; a++)
# define REP(a,b) for(int a=0; a<b; a++)
# define FORU(a,b,c) for(int a=b; a<=c; a++)
# define FORD(a,b,c) for(int a=b; a>=c; a--)

using namespace std;

int main(){

    ios :: sync_with_stdio(false);
    int N, p[100005];
    cin >> N;
    FOR(i,N) cin >> p[i];
    bool ok = 0;

    int ans = 0;
    FOR(i, N){
        if(p[i] == i){
            if(ok) ok = 0;
            else {
                ans++;
                ok = 1;
            }
        }
        else ok = 0;
    }

    cout << ans << endl;

    return 0;
}