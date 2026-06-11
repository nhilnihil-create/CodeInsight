#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N,P;
    cin>>N>>P;
    int num = 0;
    for(int i=0;i<N;i++){
        int bis;
        cin >> bis;
        if(bis%2==1 ){
            num++;
        }
    }
    if(num==0){
        cout<<(P == 0 ? (1LL << N) : 0 );
    }
    else cout <<(1LL <<(N - 1));
    
    return 0;
}
