#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include <numeric>
#include <map>
#include <cmath>
#include <iomanip>
#include <queue>
using ll =long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;

int main() {
    int N;
    string s, t;
    cin >> N;
    cin >> s >> t;
    int flag = 1;
    int arg = 2*N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N-i; j++){
            if(s.at(j+i) != t.at(j)){
                flag = 0;
            }
        }
        if(flag == 1){
            arg = i;
            break;
        }
        flag = 1;
    }
    if(arg == 2*N){
        cout << arg << endl;
        return 0;
    }
    cout << N + arg << endl;

}