#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

void reset(vector<int>& v){
    for(auto& x: v) x = 0;
}

int main()
{
    int N, M;
    cin >> N >> M;
    Vvec<int> A(N, vector<int>(M));
    for(auto& v: A){
        for(auto& x: v){
            cin >> x; x--;
        }
    }

    int left = 0, right = N;
    vector<int> num(M);
    vector<int> index(N);
    vector<int> closed(M);
    while(right - left > 1){
        int mid = (left + right) / 2;
        bool ok;
        bool loop = true;
        reset(index);
        reset(closed);

        while(loop){
            ok = true;
            reset(num);
            for(int i=0; i<N; i++){
                num[A[i][index[i]]]++;
            }
            for(int i=0; i<M; i++){
                if(num[i] > mid){
                    ok = false;
                    closed[i] = true;
                }
            }
            if(ok) loop = false;
            for(int i=0; i<N; i++){
                while(index[i] < M && closed[A[i][index[i]]]) index[i]++;
                if(index[i] >= M) loop = false;
            }
        }

        if(ok) right = mid;
        else left = mid;
    }

    cout << right << endl;
}