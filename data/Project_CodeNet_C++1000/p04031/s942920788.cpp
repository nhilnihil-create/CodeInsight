#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int a[n];
    int sum = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
    }

    int avg_ceil = int(round((double)sum / n));
    //cout<<avg_ceil<<endl;
    int cost=0;
    for(int i=0;i<n;i++)    cost += ((a[i]-avg_ceil)*(a[i]-avg_ceil));

    cout<<cost<<endl;


    return 0;
}

