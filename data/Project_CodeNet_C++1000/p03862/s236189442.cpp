#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
using namespace std;
 
int main()
{
    int N, x, tmp;   cin >> N >> x;
    ll ans = 0;
    vector<int> v(N);
    for(int i=0; i<N; i++)  cin >> v[i];
    for(int i=1; i<N; i++){
        tmp = v[i-1] + v[i];
        if(tmp > x){
            if(tmp - x <= v[i]){
                v[i] -= (tmp - x);
                ans += tmp - x;
            }else{
                v[i-1] -= (tmp - x - v[i]);
                ans += tmp - x;
                v[i] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}