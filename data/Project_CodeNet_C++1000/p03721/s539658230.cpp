#include<bits/stdc++.h>
using namespace std;
#define itn int

int main(void){
    long long n,k;
    cin >> n >> k;
    
    vector<long long> v(100010,0);
    for(int i = 0;i < n;i++){
        int a,b;
        cin >> a >> b;
        v[a-1] += b;
    }
    
    for(int i = 0;i < 100000;i++){
        k -= v[i];
        if(k <= 0){
            cout << i + 1 << endl;
            break;
        }
    }
}