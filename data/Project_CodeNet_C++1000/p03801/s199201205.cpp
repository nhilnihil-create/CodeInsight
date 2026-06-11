#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;


long long N;
pair<long long, int> data[100001];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        long long a;
        cin >> a;
        data[i] = make_pair(a, i+1);
    }
    data[N] = make_pair(0, 0);
    sort(data, data+N+1, greater<pair<long long, long long> >());
    long long ans[100001] = {};
    int next = data[0].second;
    for(int i = 0; i < N; i++){
        ans[next] += (i+1) * (data[i].first - data[i+1].first);
        next = min(next, data[i+1].second);
    }
    for(int i = 1; i <= N; i++){
        cout << ans[i] << endl;
    }
}
