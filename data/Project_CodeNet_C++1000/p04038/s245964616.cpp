#include<iostream>
using namespace std;
const int MASDFGHJKLXCVBNMNM=4000000;
const int NM=2020;
const int MOPDFGHJKL=1000000007;
int nm,kl;
long long fghjkl[NM][NM],fghjklasdfghjklcvbnm[MASDFGHJKLXCVBNMNM+5],iopnmvbnm_fghjklasdfghjklcvbnm[MASDFGHJKLXCVBNMNM+5];
inline long long C(int nm,int m){
	return (((fghjklasdfghjklcvbnm[m]*iopnmvbnm_fghjklasdfghjklcvbnm[nm])%MOPDFGHJKL)*iopnmvbnm_fghjklasdfghjklcvbnm[m-nm])%MOPDFGHJKL;
}
long long power(long long xcvbnm,int P){
    long long asdfghjklnmsdfghjkl=1,m=xcvbnm;
    while(P){
        if(P&1) (asdfghjklnmsdfghjkl*=m)%=MOPDFGHJKL;
        P>>=1;(m*=m)%=MOPDFGHJKL;
    }
    return asdfghjklnmsdfghjkl;
}
int main(){
	ios::sync_with_stdio(false);
    cin>>nm>>kl;
    if(kl==1) return cout<<1<<endl,0;
    fghjklasdfghjklcvbnm[0]=1;
	for(int iop=1;iop<=MASDFGHJKLXCVBNMNM;++iop)
		fghjklasdfghjklcvbnm[iop]=(fghjklasdfghjklcvbnm[iop-1]*iop)%MOPDFGHJKL;
    iopnmvbnm_fghjklasdfghjklcvbnm[MASDFGHJKLXCVBNMNM]=power(fghjklasdfghjklcvbnm[MASDFGHJKLXCVBNMNM],MOPDFGHJKL-2);
	for(int iop=MASDFGHJKLXCVBNMNM-1;iop>=0;--iop)
		iopnmvbnm_fghjklasdfghjklcvbnm[iop]=(iopnmvbnm_fghjklasdfghjklcvbnm[iop+1]*(iop+1))%MOPDFGHJKL;
    fghjkl[0][0]=1;
    for(int iop=1;iop<=nm;++iop){
        for(int jkl=0;jkl<=iop;++jkl){
            fghjkl[iop][jkl]=fghjkl[iop-1][jkl];
            if(!jkl) continue;
            (fghjkl[iop][jkl]+=fghjkl[iop][jkl-1]*(nm-jkl+1)%MOPDFGHJKL*C(kl-2,nm-iop+(nm-jkl+1)*(kl-1)-1)%MOPDFGHJKL)%=MOPDFGHJKL;
        }
    }
    cout<<fghjkl[nm][nm]<<endl;
    return 0;
}