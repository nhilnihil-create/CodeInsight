#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int is_up=0;
    long long int preA=-1;
    int ans=1;
    for(int n=0; n<N; n++) {
        long long int A;
        cin >> A;
        if(preA==-1) {
            preA=A;
        } else {
            if(is_up==0) {
                if(preA<A) {
                    is_up=1;
                } else if(preA>A) {
                    is_up=-1;
                }
            } else if(is_up>0) {
                if(preA>A) {
                    ans++;
                    is_up=0;
                    preA=-1;
                }
            } else {
                if(preA<A) {
                    ans++;
                    is_up=0;
                    preA=-1;
                }
            }
        }
        preA = A;
    }
    
    cout << ans << endl;


    return 0;
    
}