#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0; i<N; i++)


int main(){
    int N, K, A=0, pn, pk;
    cin >> N >> K;
    vector<int> vec(N);
    rep(i,N){
        cin >> vec.at(i);
        pk=max(K, vec.at(i))-min(K, vec.at(i));
        A+=2*(min(vec.at(i), pk));
    }

    cout << A << endl;
}