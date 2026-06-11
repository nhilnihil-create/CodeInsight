#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
using namespace std;

int main(){
    int N;  ll K, cnt;   cin >> N >> K;
    vector<pair<int, int> > p(N);
    for(int i=0; i<N; i++)  cin >> p[i].first >> p[i].second;
    sort(all(p));
    cnt = 0;
    for(int i=0; i<N; i++){
        cnt += p[i].second;
        if(cnt >= K){
            cout << p[i].first << endl;
            return 0;
        }
    }
}