#include<bits/stdc++.h>
using namespace std;
int main(){
int n , l ;
cin>>n>>l;
int A[n+1];
for(int i=1 ; i<=n ; i++) cin>>A[i];
bool flag = 0;
int pos = 0;
for(int i=1 ; i<n ; i++){
    if(A[i]+A[i+1]>=l){
        flag = 1;
        pos = i;
        break;
    }
}


if(flag == 0){
    cout<<"Impossible"<<endl;
    return 0;
}
else{
    cout<<"Possible"<<endl;

for(int i=1 ; i<pos ; i++){
    cout<<i<<endl;
}

for(int i=n-1 ; i>=pos ; i--)
    cout<<i<<endl;
}
}
