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
#include<bitset>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    LL a,b,c,d,e,f,g;
    cin >> a >> b >> c >> d >> e >> f >> g;

    if(a > 0 && d > 0 && e > 0){
        if((a%2 == 0 && d%2 == 0 && e%2 == 0)||(a%2 == 1 && d%2 == 1 && e%2 == 1)){
            cout << b+a+d+e << endl;
        }else{
            cout << b+a+d+e-1 << endl;
        }
    }else{
        cout << b+(a/2)*2+(d/2)*2+(e/2)*2 << endl;
    }
    
    return 0;
}