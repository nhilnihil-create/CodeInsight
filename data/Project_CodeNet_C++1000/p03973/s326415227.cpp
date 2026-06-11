#include <iostream>

using namespace std;

int main(){
    int N;
    int A[100000];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int prev_max = 1;
    long ans = A[0]-1;
    for(int i = 1; i < N; i++){
        int tmp = prev_max+1;
        if(A[i] == tmp){
            prev_max = tmp;
        }else if(A[i]%tmp == 0){
            ans += (A[i]/tmp-1);
        }else{
            ans += (A[i]/tmp);
        }
    }
    cout << ans << endl;
}