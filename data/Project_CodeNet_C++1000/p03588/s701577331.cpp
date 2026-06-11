#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i = 0;i < n;i++)cin >> a[i] >> b[i];
    int max = 0,c = 0;
    for(int i = 0;i < n;i++){
        if(max < a[i]){
            max = a[i];
            c = b[i];
        }
    }
    cout << max+c;
}