#include<iostream>
using namespace std;
const int NMAX=(int) 1e5+1; 

int main(){
    int N;
    cin >> N;
    int A;
    int AN[NMAX]={};
    int even, odd, ans;

    for(int i=0; i<N; i++){
        cin >> A;
        AN[A]++;
    }

    even=0;
    odd=0;
    for(int i=0; i<NMAX; i++){
        if( AN[i]>0 && AN[i]%2==0 ){
            even++;
        }else if( AN[i]>0 ){
            odd++;
        }
    }

    if( even%2==1 ){
        ans=even+odd-1;
    }else{
        ans=even+odd;
    }

    cout << ans << endl;

    return 0;
}