#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin>>N;
    cin>>K;
    vector<int> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    int minDistance = 0;
    for(int i=0;i<N;i++){
        minDistance += (2*min(abs(v[i]),abs(v[i]-K)));
    }
    cout<<minDistance<<endl;
}