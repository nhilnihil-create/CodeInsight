#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    vector<int> data(3);
    int sum=0;
    bool ok=false;
    for (int i=0; i<3 ;i++) {
        cin>>data[i];
        sum+=data[i];
    }
    for (int i=0; i<3; i++){
        long long ans;
        ans = sum-data[i];
        if (data[i]==ans) ok = true;
    }
    if (ok) cout<<"Yes"<<endl;
    else if (!ok) cout<<"No"<<endl;
}
