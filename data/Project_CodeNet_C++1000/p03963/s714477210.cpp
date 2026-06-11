#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC40(void);
void ABC41(void);
void ABC42(void);
void ABC43(void);
void ABC44(void);
void ABC45(void);
void ABC46(void);
void ABC47(void);
void ABC48(void);
void ABC49(void);

int main(void){
    ABC46();
}

void ABC46(){
    long long int n,k,i,ans;
    cin>>n>>k;
    ans=k;
    for(i=1;i<n;i++){
        ans*=(k-1);
    }
    cout<<ans<<endl;
}