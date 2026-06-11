#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long> a(3*n);
    for(int i=0; i<3*n; i++){
        cin >> a[i];
    }
    sort(a.rbegin(),a.rend());
    long long sm=0;
    for(int i=0; i<2*n; i++){
        if(i%2==1){
//            cout << a[i] << endl;
            sm += a[i];
        }
    }
    cout << sm << endl;
}


