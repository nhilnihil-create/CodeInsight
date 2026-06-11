#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int N;cin>>N;
    string S,T;cin>>S>>T;
    for(int i=0;i<N;i++){
        for(int j=0;j<N-i;j++){
            if(S[j+i]!=T[j]){
                break;
            }
            else if(j==N-i-1){
                cout<<N+i;
                return 0;
            }
        }
    }
    cout<<2*N<<endl;
    return 0;
}
