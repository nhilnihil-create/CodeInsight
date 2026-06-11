#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int N, C, K;
    cin >> N >> C >> K;
    int T[100010];
    for(int i = 0; i < N; i++) cin >> T[i];
    int take = 0;
    int bus = 0;
    int first = 0;
    sort(T,T+N);
    for(int i = 0; i < N;){
        while(take < C && T[i+take] <= T[i]+K){
            take++;//while内のtake +1で出される
        }
        bus++;
        i += take;
        take = 0;
    }
    cout << bus << endl;
    return 0;
}