#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    int sum=0;
    cin >> N;
    cin >> K;
    int x[N];
    for(int i=0; i<N;i++){
        cin >> x[i];
        if(x[i] > (K-x[i]))
            sum += 2*(K-x[i]);
        else
            sum += 2*x[i];
    }
    cout << sum << endl;
}