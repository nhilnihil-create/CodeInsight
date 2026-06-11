#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long N;
    cin >> N ;
    vector<long long> A(N);
    long long check = 0; 
    for(long long i = 0; i < N; i++){
        cin >> A.at(i);
        if(A.at(i) % 2 == 1){
            check++;
        }
    }
    if(check % 2 == 0){
        printf("YES");
    }
    else{
        printf("NO");
    }
    
}