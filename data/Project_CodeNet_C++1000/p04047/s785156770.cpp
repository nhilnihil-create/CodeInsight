#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main(void){

    int n;
    cin >> n;

    vector<int> ar(2*n,0);

    for(int i=0;i<2*n;i++){
        cin >> ar[i];
    }

    sort(ar.begin(),ar.end());

    ll sum = 0;

    for(int i=0;i<2*n-1;i+=2){
        sum += min(ar[i],ar[i+1]);
    }

    cout << sum << endl;

    return 0;
}
