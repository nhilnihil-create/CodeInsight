#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int M;
int bit[1000010];
void add(int a, int w){
    for(int x = a; x <= M; x += x & -x) bit[x] += w;
}
int sum(int a){
    int ret = 0;
    for(int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}


pair<int, int> lr[300000];
pair<int, int> dn[300000];

int main(){
    int N;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> lr[i].first >> lr[i].second;
        dn[i].first = lr[i].second - lr[i].first + 1;
        dn[i].second = i;
    }
    sort(dn, dn+N);
    int cntLessThanD = 0;
    for(int d = 1; d <= M; d++){
        while(cntLessThanD < N && dn[cntLessThanD].first < d){
            int n = dn[cntLessThanD].second;
            add(lr[n].first, 1);
            add(lr[n].second + 1, -1);
            cntLessThanD++;
        }
        int ans = 0;
        for(int i = 1; i * d <= M; i++){
            ans += sum(i * d);
        }
        ans += N - cntLessThanD;
        cout << ans << endl;
    }
}
