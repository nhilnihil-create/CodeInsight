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
    int N, M;   cin >> N >> M;
    vector<int> v(N,0), c(N,1);
    v[0] = 1;
    for(int i=0; i<M; i++){
        int x, y;   cin >> x >> y;
        if(v[x-1] == 1 && c[x-1] == 1){
            v[x-1] = 0;
            v[y-1] = 1;
        }else if(v[x-1] == 1){
            v[y-1] = 1;
        }
        c[x-1] -= 1;
        c[y-1] += 1;
    }
    int ans = 0;
    for(int i=0; i<N; i++)  ans += v[i];
    cout << ans << endl;
    return 0;
}