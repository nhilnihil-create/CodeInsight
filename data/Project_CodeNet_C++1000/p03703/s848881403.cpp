#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

const int N = 2e5 + 5;

int n;

long long k, sum[N], a[N], b[N], sbd[N], cnt, total, bit[N];

vector<pair<long long, int>> vec;

void update(int pos){
    while(pos <= N - 5){
        bit[pos] += 1;
        pos += pos & (-pos);
    }
}

int get(int pos){
    int sum1 = 0;
    while(pos > 0){
        sum1 += bit[pos];
        pos -= pos & (-pos);
    }
    return sum1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = a[i];
        sum[i] += sum[i - 1];
    }
    for(int i = 1; i <= n; i++){
        b[i] = sum[i] - 1ll * i * k;
        vec.pb({b[i], i});
    }
    sort(vec.begin(), vec.end());
    sbd[vec[0].se] = ++cnt;
    for(int i = 1; i < vec.size(); i++){
        if(vec[i].fi != vec[i - 1].fi)
            sbd[vec[i].se] = ++cnt;
        else
            sbd[vec[i].se] = cnt;
    }
    for(int i = 1; i <= n; i++){
        if(sum[i] - 1ll * i * k >= 0)
            total++;
        total += get(sbd[i]);
        update(sbd[i]);
    }
    cout << total << "\n";
}
