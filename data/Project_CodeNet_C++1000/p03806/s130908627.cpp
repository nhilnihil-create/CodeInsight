#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>

long long PRIME = 1e9 + 7;
using namespace std;

vector<vector<int>> E;


int main(){ 
    long long N, Ma, Mb;
    cin >> N >> Ma >> Mb;

    vector<int> a(N), b(N), c(N);

    int sum_a = 0;
    int sum_b = 0;

    for(int i = 0; i < N; ++i){
        cin >> a.at(i) >> b.at(i) >> c.at(i);
        sum_a += a[i];
        sum_b += b[i];
    }

    if(sum_a < Ma || sum_b < Mb){
        cout << -1;
        return 0;
    }

    int big = 100000;
    vector<vector<int>> table(sum_a + 1, vector<int>(sum_b + 1, big));

    table[0][0] = 0;

    for(int i = 0; i < N; ++i){
        for(int num_a = sum_a; num_a >= a[i]; --num_a){
            for(int num_b = sum_b; num_b >= b[i]; --num_b){
                if(table[num_a - a[i]][num_b - b[i]] != big){
                    table[num_a][num_b] = min<int>(table[num_a][num_b], table[num_a - a[i]][num_b - b[i]] + c[i]);
                }
            }
        }

    }


    int max_num = min<int>(sum_a / Ma, sum_b / Mb);
    int min_c = big;

    for(int i = 1; i <= max_num; ++i){
        min_c = min<int>(min_c, table[Ma * i][Mb * i]);
    }

    if(min_c == big){
        cout << -1;
    }
    else{
        cout << min_c;
    }
}

