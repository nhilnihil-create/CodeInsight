#include<bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int ar[3];
    for(int i=0;i<3;++i) cin>>ar[i];
    sort(ar,ar+3);
	cout<<accumulate(ar,ar+3,0)-ar[2];
    return 0;
}