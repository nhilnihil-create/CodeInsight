#include <bits/stdc++.h>
using namespace std;

struct BIT {
    long long n;
    vector<long long> dat;

    void initialize(long long n_input){
        n = n_input + 1;
        dat.resize(n+1);
        for(int i = 0; i<=n; i++) dat[i] = 0;
    }

    long long sum(long long i){
        long long s = 0;
        while(i >= 0){
            s += dat[i];
            i = (i & (i+1)) - 1;
        }
        return s;
    }

    void add(long long i, long long x){
        while(i <= n){
            dat[i] += x;
            i |= i+1;
        }
    }
};

int N, M;
int ls[300000], rs[300000];
vector<pair<int, int>> pairs;

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> ls[i] >> rs[i];
        pairs.push_back(make_pair(rs[i]-ls[i], i));
    }
    sort(pairs.begin(), pairs.end());

    BIT bit;
    bit.initialize(M+2);

    int pt = 0;
    for(int m=1; m<=M; m++){
        while(pt<N){
            int i = pairs[pt].second;
            if(rs[i]-ls[i]+1 < m){
                pt += 1;
                bit.add(ls[i], 1);
                bit.add(rs[i]+1, -1);
            }else{
                break;
            }
        }
        int sum = N - pt;
        for(int k=1; k<=M/m; k++){
            sum += bit.sum(k*m);
        }
        cout << sum << endl;
    }
    return 0;
}