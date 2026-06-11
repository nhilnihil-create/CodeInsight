#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>
#include <cmath>
#include <stack>
#include <iomanip>

using namespace std;
typedef long long ll;
using Pll = pair<ll,ll>;

const ll INF = 1LL<<60;
const ll MOD = 1000000007;

//cout << fixed << setprecision(10);

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;

    string ans = "S";
    ans+='S';
    for(int i=1;i<N;i++){
        if(S[i]=='o'){
            if(ans[i]=='S') ans += ans[i-1];
            else ans += (ans[i-1]=='S'?'W':'S');
        }
        else{
            if(ans[i]=='S') ans += (ans[i-1]=='S'?'W':'S');
            else ans += ans[i-1];
        }
    }
    if((ans[0]==ans[N]) && ((S[0]=='o' && ans[1]==ans[N-1]) || (S[0]=='x' && ans[1]!=ans[N-1]))){
        cout << ans.substr(0,N) << endl;
        return 0;
    }

    ans = "S";
    ans+='W';
    for(int i=1;i<N;i++){
        if(S[i]=='o'){
            if(ans[i]=='S') ans += ans[i-1];
            else ans += (ans[i-1]=='S'?'W':'S');
        }
        else{
            if(ans[i]=='S') ans += (ans[i-1]=='S'?'W':'S');
            else ans += ans[i-1];
        }
    }
    if((ans[0]==ans[N]) && ((S[0]=='o' && ans[1]==ans[N-1]) || (S[0]=='x' && ans[1]!=ans[N-1]))){
        cout << ans.substr(0,N) << endl;
        return 0;
    }
    
    ans = "W";
    ans += 'S';
    for(int i=1;i<N;i++){
        if(S[i]=='o'){
            if(ans[i]=='S') ans += ans[i-1];
            else ans += (ans[i-1]=='S'?'W':'S');
        }
        else{
            if(ans[i]=='S') ans += (ans[i-1]=='S'?'W':'S');
            else ans += ans[i-1];
        }
    }
    if((ans[0]==ans[N]) && ((S[0]=='x' && ans[1]==ans[N-1]) || (S[0]=='o' && ans[1]!=ans[N-1]))){
        cout << ans.substr(0,N) << endl;
        return 0;
    }

    ans = "W";
    ans += 'W';
    for(int i=1;i<N;i++){
        if(S[i]=='o'){
            if(ans[i]=='S') ans += ans[i-1];
            else ans += (ans[i-1]=='S'?'W':'S');
        }
        else{
            if(ans[i]=='S') ans += (ans[i-1]=='S'?'W':'S');
            else ans += ans[i-1];
        }
    }
    if((ans[0]==ans[N]) && ((S[0]=='x' && ans[1]==ans[N-1]) || (S[0]=='o' && ans[1]!=ans[N-1]))){
        cout << ans.substr(0,N) << endl;
        return 0;
    }

    cout << -1 << endl;

    return 0;
}