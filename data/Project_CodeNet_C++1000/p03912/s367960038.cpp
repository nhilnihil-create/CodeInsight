#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <numeric>
#include <functional>
#include <limits.h>
#include <utility>
#include <stack>

using namespace std;

#define fs first
#define sc second

typedef long long ll;
typedef pair<ll, ll> P;


int main(){
    int N, M, x[101000];
    P v[101000];
    cin >> N >> M;
    fill(x, x+101000, 0);
    for(int i = 0; i < N; i++){
        int y;  cin >> y;
        x[y]++;
    }

    for(int i = 0; i < 101000; i++){
        v[i] = P(0, 0);
    }
    for(int i = 0; i < 101000; i++){
        v[i % M].fs += x[i];
        v[i % M].sc += x[i] / 2;
    }

    bool check[101000];
    fill(check, check+101000, false);

    int res = 0;
    for(int i = 0; i < M; i++){
        if(check[i]){
            continue;
        }
        int opponent = (M - i) % M;
        if(opponent == i){
            res += v[i].fs / 2;
        }
        else{
            res += min(v[i].fs, v[opponent].fs);
            int maxIndex = v[i].fs > v[opponent].fs ? i : opponent;
            int minIndex = v[i].fs > v[opponent].fs ? opponent : i;
            res += min(v[maxIndex].sc, (v[maxIndex].fs - v[minIndex].fs) / 2);
        }
        check[i] = check[opponent] = true;
    }

    cout << res << endl;



    return 0;
}