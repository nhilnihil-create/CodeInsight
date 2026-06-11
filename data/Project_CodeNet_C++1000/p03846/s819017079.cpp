#include<iostream>
#include<map>
#include<math.h>
using namespace std;

int main(){
    int N;
    map<int, int> cnt;
    cin >> N;
    int require = 1;
    if (N % 2 == 1) require--;
    for (int i=0; i<N; i++){
        int A; cin >> A;
        if (A%2 != require){
            cout << 0 << endl;
            return 0;
        }
        cnt[A]++;
        if (cnt[A] > 2){
            cout << 0 << endl;
            return 0;
        }
    }
    if (require == 0){
        if (cnt[0] == 1){
            cnt.erase(0);
        }else{
            cout << 0 << endl;
            return 0;
        }
    }
    for (auto x : cnt){
        if (x.second != 2){
            cout << 0 << endl;
            return 0;
        }
    }
    long long ans=1;
    for (int i=0; i< N/2; i++){
        ans *= 2;
        ans %= 1000000007; 
    }
    cout << ans << endl;
    return 0;
}