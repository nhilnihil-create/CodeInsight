#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef long double ld;
 
using namespace std;

int main(){
    int N, C, K, T, cnt, ans, tmp;    cin >> N >> C >> K;
    tmp = 0;
    ans = 0;
    cnt = 0;
    vector<int> v(N);
    for(int i=0; i<N; i++)  cin >> v[i];
    sort(all(v));
    for(int i=0; i<N; i++){
        T = v[i];
        if(tmp == 0)    tmp = T;
        if(T <= tmp+K)  cnt++;
        else{
            tmp = T;
            cnt = 1;
            ans++;
        }
        if(cnt == C){
            ans++;
            cnt = 0;
            tmp = 0;
        }
    }
    if(cnt > 0) ans++;
    cout << ans << endl;
    return 0;
}