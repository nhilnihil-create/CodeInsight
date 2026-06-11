#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,x;
    cin >> N >>x;
    if(x==1 || x == 2*N-1){
        cout <<"No" << endl;
        return 0;
    }
    cout <<"Yes" << endl;
    if(x==N){
        for(int i=1;i<2*N;i++){
            cout <<i <<"\n";
        }
        return 0;
    }
    if(x<N){
        for(int i=0;i<(N-2);i++){
            cout << N*2-1-i << "\n";
        }
        cout << x << "\n";
        cout << 1 << "\n";
        for(int i=N;i<2*N;i++){
            if( N*2+1-i==x){
                continue;
            }
            cout << N*2+1-i <<"\n";
        }
        return 0;
    }

     for(int i=0;i<(N-2);i++){
            cout << i+1 << "\n";
        }
        cout << x << "\n";
        cout << 2*N-1 << "\n";
        for(int i=N;i<2*N;i++){
            if(i-1 ==x){
                continue;
            }
            cout << i-1 <<"\n";
        }




    return 0;
}