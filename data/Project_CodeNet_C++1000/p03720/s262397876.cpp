#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N=0;
    int M=0;
    int douro=0;
    cin >> N >> M;
    M = M*2;
    vector<int> toshi(N+1);
    for(int i=1;i<=M;i++){
        cin >> douro;
        toshi[douro]++;
    }
    for(int i=1;i<=N;i++){
        cout << toshi[i] << endl;
    }
}
