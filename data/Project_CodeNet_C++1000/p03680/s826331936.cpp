#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n,c=0;
    cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        a.push_back(val);
    }
    int j=0, now=1;
    for(;;){
            now = a[now-1];
            if(now == 2){
                cout << c+1;
                break;
            }
            if(c>=n){
                cout << "-1";
                break;
            }
        c++;
    }

}