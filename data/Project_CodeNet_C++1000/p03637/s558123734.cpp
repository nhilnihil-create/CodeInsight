#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,fourcnt=0,twocnt=0;
    cin>>n;
    vector<int> a(n);
    
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i] % 4 == 0) fourcnt++;
        if(a[i] % 2 == 0 && a[i] % 4 != 0){
            twocnt++;       
            if(twocnt % 2 == 0){
                fourcnt++;
            } 
        }
    }

    string ans;

    if(n % 2 != 0 && fourcnt >= n/2){
        ans = "Yes";
    }

    else if(n % 2 == 0 && twocnt == n){
        ans = "Yes";
    }

    else if(n % 2 == 0 && fourcnt >= n/2){
        ans = "Yes";
    }

    else ans = "No";

    cout<<ans<<endl;

    return 0;
}