#include<iostream>
#include<algorithm>
using namespace std;

long long N, L, T;
long long X[100000], W[100000];
pair<long long, int> X_after[100000];

int main(){
    cin >> N >> L >> T;
    for(int i = 0; i < N; i++){
        cin >> X[i] >> W[i];
        int j;
        if(W[0] == 1){
            j = i;
        }else{
            j = -i;
        }
        if(W[i] == 1){
            X_after[i] = make_pair((X[i] + T) % L, j);
        }else{
            X_after[i] = make_pair((X[i] + (L - 1) * T) % L, j);
        }
    }
    sort(X_after, X_after + N);
    long long meet_count = 0;
    for(int i = 1; i < N; i++){
        long long dist = 0;
        if(W[0] == 1){
            dist = ((X[i] + L) - X[0]) % L;
        }else{
            dist = ((X[0] + L) - X[i]) % L;
        }
        if(W[0] != W[i]){
            // 2*T > (n - 1)*L + dist
            long long n = 0;
            if(2*T > dist){
                n = (2*T - dist - 1) / L + 1;
            }
            meet_count += n;
        }
    }
    meet_count %= N;
    int start;
    for(int i = 0; i < N; i++){
        if(X_after[i].second == 0){
            if(W[0] == 1){
                start = (i + N - meet_count) % N;
            }else{
                start = (i + meet_count) % N;
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << X_after[(start + i) % N].first << endl;
    }
}
