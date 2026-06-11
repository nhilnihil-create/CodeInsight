#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N, K;
    int x;
    cin >> N;
    cin >> K;

    int distance = 0;

    rep(i, N)
    {
        cin >> x;
        if(x > K / 2){
            distance += (K - x) * 2;
        }else{
            distance += x * 2;
        }
    }

    cout << distance << endl;

    return 0;
}