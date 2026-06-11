#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    cin >> N;
    vector<long long> A(N);
    long long sum = 0;
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        sum += A.at(i);
    }
    if(sum % 2 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}