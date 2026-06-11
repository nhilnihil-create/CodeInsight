#include<bits/stdc++.h>
using namespace std;
template<class T> void chmax(T& x, T y){if(x < y) x = y;}
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
#define p pair<int,int>
int N;
vector<int> as;
map<int,int> mp;

int main(){
    cin >> N;
    int m = 1 << 30, M = 0;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        mp[a]++;

        chmax(M, a);
        chmin(m, a);
    }
    bool flag = true;
    if(M - m > 1) flag = false;
    if(M - m == 1){
        if(mp[m] + 1 > M || M > mp[m] + (mp[M] / 2)) flag = false;
    }
    if(M - m == 0){
        flag  = false;
        if(m + 1 == N) flag = true;
        if(m * 2 <= N) flag = true;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}