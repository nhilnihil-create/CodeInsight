#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int l,r;
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> l >> r;
        int s;
        s = r-l+1;
        sum += s;
    }
    cout << sum << endl;
}