#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int n;cin>>n;
    int k;cin>>k;
    int arr[n];

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }

    int r=0;
    for(int i=0;i<n;i++){
        r += min(vec.at(i)*2,(k-vec.at(i))*2);
    }

    cout << r << endl;
}