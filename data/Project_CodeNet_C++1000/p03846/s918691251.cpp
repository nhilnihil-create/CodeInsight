#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    bool flag = true;
    int m = a.size();
    if(a[0] == 0 && m % 2 == 1){
        for(int i=1; i<m; i++){
            if(a[i] != (i+1) / 2 * 2){
                flag = false;
                break;
            }
        }
    }
    else if(a[0] == 1 && m % 2 == 0){
        for(int i=0; i<m; i++){
            if(a[i] != i / 2 * 2 + 1){
                flag = false;
                break;
            }
        }
    }
    else flag = false;

    long long int count = 1;
    for(int i=1; i<=m/2; i++){
        count *= 2;
        count %= MOD;
    }
    
    if(flag == true)  cout << count << endl;
    if(flag == false) cout << 0 << endl;
    return 0;
}