#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main() {
    int N,M,K; cin >> N >> M >> K;
    bool result=false;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            if(i*M+j*N-2*i*j == K) {result=true;break;}
        }
    }
    if(result) cout << "Yes" << endl;
    else cout << "No"<< endl;
}

