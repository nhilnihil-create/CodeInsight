#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(3*n);
    for(int i = 0;i < 3*n;i++){
        cin >> a[i];
    }
    /**/
    sort(a.begin(), a.end());

    long long ans = 0;
    for(int i = n*3 - 2;i >= n*3 - n*2;i -= 2){
        ans += a[i];
        //cout << a[i] << endl;
    }

    cout << ans << endl;
    return 0;
}