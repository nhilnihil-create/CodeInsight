#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int one=0,four=0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a%4==0) four++;
        if(a%2==1) one++;
    }
    if(one<=four || four>=n/2) cout << "Yes" << endl;
    else cout << "No" << endl;
}