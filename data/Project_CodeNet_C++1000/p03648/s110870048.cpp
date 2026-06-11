#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL k;
    cin >> k;

    LL a = (k+49)/50;

    LL b = a+49;
    vector<LL> ans(50,b);
    for(LL i = 0; i < 50*a - k; i++){
        ans[i] -= 50;
        for(LL j = 0; j < 50; j++){
            if(i != j){
                ans[j]++;
            }
        }
    }

    cout << 50 << endl;

    for(LL i = 0; i < 50; i++){
        if(i > 0)cout << " ";
        cout << ans[i];
    }
    cout << endl;
    
    return 0;
}