#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC70(void);
void ABC71(void);
void ABC72(void);
void ABC73(void);
void ABC74(void);
void ABC75(void);
void ABC76(void);
void ABC77(void);
void ABC78(void);
void ABC79(void);

int main(void){
    ABC73();
}

void ABC73(){
    int i,l,r,n,sum=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>l>>r;
        sum+=(r-l)+1;
    }
    if(sum>=100000)cout<<100000<<endl;
    else cout<<sum<<endl;
}