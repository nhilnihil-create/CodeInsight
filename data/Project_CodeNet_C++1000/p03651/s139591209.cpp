#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<numeric>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
using namespace std;

int main()
{
    int N, K; cin >> N >> K;
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
        if(v[i] == K){
            cout << "POSSIBLE";
            return 0;
        }
    }
    sort(all(v));
    if(v[N-1] < K){
        cout << "IMPOSSIBLE";
        return 0;
    }
    int t, dv;
    dv = 2000000000;
    for(int i=1; i<N; i++){
        t = v[i] - v[i-1];
        if(t > 0)   dv = min(dv,t);   
    }
    for(int i=0; i<N; i++){
        if(v[i]%dv != 0){
            cout << "POSSIBLE";
            return 0;
        }
    }
    if(K%dv == 0)   cout << "POSSIBLE";
    else    cout << "IMPOSSIBLE";
}