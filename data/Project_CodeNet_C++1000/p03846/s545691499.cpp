#include<iostream>
using namespace std;

int main(){
    const int MOD = 1000000007;
    int N;
    cin >> N;
    bool isEven = N%2 ==0;
    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    int check[N];
    for(int i=0; i<N; i++){
        check[i] = 2;
    }

    for(int i=0; i<N; i++){
        if(isEven){
            if(A[i] % 2 == 0){
                cout << 0 << '\n';
                return 0;
            }else{
               check[A[i]]--;
               if(check[A[i]]<0) {
                    cout << 0 << '\n';
                    return 0;
               }
            }
        }else{
            if(A[i] % 2 != 0){
                cout << 0 << '\n';
                return 0;
            }else{
               check[A[i]]--;
               if(check[A[i]]<0) {
                    cout << 0 << '\n';
                    return 0;
               }
            }
        }
    }
    if(isEven){
        if(check[0]!=2){
            cout << 0 << '\n';
            return 0;
        }
    }else{
        if(check[0]!=1){
            cout << 0 << '\n';
            return 0;
        }
    }

    int level = N/2;
    int ans = 1;
    for(int i=0; i<level; i++){
        ans = (ans*2)%MOD;
    }
    cout << ans << '\n';
}