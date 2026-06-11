#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<numeric>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main()
{
    int N, M, t;   cin >> N >> M;
    vector<int> x(100000,0), p(M,0);
    for(int i=0; i<N; i++){
        cin >> t;
        x[t-1]++;
        p[t%M]++;
    }
    int tmp, ans, c;
    ans = 0;
    for(int i=1; i<M/2+1; i++){
        if(M%2==0 && i == M/2){
            ans += p[i]/2;
            c = 0;
        }else{
            ans += min(p[i],p[M-i]);
            c = abs(p[i] - p[M-i]);
        }
        if(p[i] > p[M-i])   tmp = i;
        else    tmp = M-i;
        for(int j=tmp-1; j<100000; j+=M){
            if(x[j] > 1 && c > 1){
                while(x[j] > 1 && c > 1){
                    ans++;
                    c -= 2;
                    x[j] -= 2;
                }
            }
        }
    }
    ans += p[0]/2;
    cout << ans << endl;
    return 0;
}