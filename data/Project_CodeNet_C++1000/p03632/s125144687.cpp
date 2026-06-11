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
    ABC70();
}

void ABC70(){
    int a,b,c,d,ans;
    cin>>a>>b>>c>>d;
    ans=min(b,d)-max(a,c);
    if(ans>0)cout<<ans<<endl;
    else cout<<0<<endl;
}