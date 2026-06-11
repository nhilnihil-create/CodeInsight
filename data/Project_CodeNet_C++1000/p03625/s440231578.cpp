#include<bits/stdc++.h>
#define int long long
using namespace std;
main(){
int n;
cin>>n;
int A[n];
for(int i=0 ; i<n ;i++)
    cin>>A[i];

sort(A , A+n);
vector<int>sides;
for(int i=n-1 ; i>=1 ; i--){
    if(A[i] == A[i-1])
    sides.push_back(A[i]) , i--;

}

if(sides.size()>=2){
    cout<<sides[0] * sides[1]<<endl;
}

else
    cout<<0<<endl;
}
