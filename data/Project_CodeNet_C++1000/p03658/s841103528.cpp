#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n,k,sum=0;
    vector<int> a;
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        int data;
        cin >> data;
        a.push_back(data);
    }
    sort(a.rbegin(),a.rend());
    for(int i=0; i<k; ++i){
        sum+=a[i];
    }
    cout << sum;
}