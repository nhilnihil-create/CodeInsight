#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,K;
    cin >> N >> K ;
    int i=0;
    int x[N];
    int dist=0;

    for(i=0; i<N; i++){
        cin >> x[i];
        if(abs(x[i]-K) < x[i]){
            dist+=abs(x[i]-K)*2;
        }else{
            dist+=x[i]*2;
        }
    }

    cout << dist << endl;
}