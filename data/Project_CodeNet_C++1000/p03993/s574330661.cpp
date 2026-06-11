#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A.at(i);
    for(int i=0; i<N; ++i) A.at(i) -= 1;

    int ans = 0;

    for(int i=0; i<N; ++i){
        if(i == A.at(A.at(i))) ans++;
    }
    cout << ans / 2 << endl;
}