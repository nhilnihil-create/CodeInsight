#include<iostream>
//#include<vector>
using namespace std;

int main(){
    long long n,T;
    cin >> n >> T;
    long long t[200000],ans = 0;
    for(int i = 0;i < n;i++){
        cin >> t[i];
        if(i > 0){
            ans += min(T,t[i] - t[i - 1]);
        }
    }

    cout << ans + T << endl;

    return 0;
}