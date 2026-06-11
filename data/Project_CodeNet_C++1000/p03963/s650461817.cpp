#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,K;
    cin>>N>>K;
    long long summ=K;
    for(int i=2;i<=N;i++){
        summ*=(K-1);
    }
    cout <<summ<<endl;
    
}