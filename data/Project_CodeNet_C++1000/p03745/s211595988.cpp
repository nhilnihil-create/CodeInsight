#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int res=0;
    for(int i=0;i<n;i++){
        while(i+1<n&&a[i]==a[i+1]) i++;
        if(i+1<n&&a[i]<a[i+1]){
            while(i+1<n&&a[i]<=a[i+1]) i++;
        }
        else if(i+1<n&&a[i]>a[i+1]){
            while(i+1<n&&a[i]>=a[i+1]) i++;
        }
        res++;
    }
    cout << res << endl;
}