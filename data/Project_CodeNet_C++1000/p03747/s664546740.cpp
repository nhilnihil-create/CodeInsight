#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
using namespace std;

long long X[100000];
int W[100000];
int main(){
    long long N;
    long long T;
    long long L;
    cin >> N >> L >> T;
    for(int i = 0; i < N; i++){
        cin >> X[i] >> W[i];
    }
    
    long long pass_origin_from_right = 0;
    long long pass_origin_from_left = 0;
    for(int i = 0; i < N; i++){
        if(W[i] == 1){
            pass_origin_from_left += (X[i] + T) / L;
            X[i] = (X[i] + T) % L;
        } else {
            if(X[i] - T < 0){
                pass_origin_from_right += (abs(X[i] - T) - 1) / L + 1;
            }
            X[i] = ((X[i] - T) % L + L) % L;
        }
    }
    sort(X, X + N);
    //cout << pass_origin_from_left << " " << pass_origin_from_right << endl;
    int first_ant_pos = ((pass_origin_from_left - pass_origin_from_right) % N + N) % N;
    //cout << first_ant_pos  << endl;
    for(int i = 0; i < N; i++){
        cout << X[(first_ant_pos + i) % N] << endl;
    }
}