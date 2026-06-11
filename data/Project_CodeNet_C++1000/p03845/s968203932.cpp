#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

bool chmin(int& a, int b){
    if (a > b) a = b; return true;
    return false;
}

int main(){
    int N, M;
    vector<int> T, P, X;
    cin >> N;
    for (int i=0; i<N; i++){
        int t;
        cin >> t;
        T.push_back(t);
    }
    int total = accumulate(T.begin(), T.end(), 0);
    cin >> M;
    for (int i=0; i<M; i++){
        int p, x;
        cin >> p >> x;
        cout << total - T[p-1] + x << endl;;
    }
    return 0;
}