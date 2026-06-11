#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];

    if(n%2 == 0){
        for(int i=n-1;i>0;i -= 2){//偶数番目（添え字は奇数）
            cout << vec[i] << " ";
        }
        for(int i=0;i<n-1;i += 2){
            cout << vec[i] << " ";
        }cout << endl;
    }else {
        for(int i=n-1;i>=0;i -= 2){
            cout << vec[i] << " ";
        }
        for(int i=1;i<n;i += 2){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
}