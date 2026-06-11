//题意：n个人编号1-n站成一排，每个人左边的人数和右边的人数的差的绝对值为Ai，求可能的站的方案数的个数；n范围1e5
//方案数要取模1e9+7，没有这样的方案就输出0 
//思路： 看了一下样例，感觉找到了规律啊。
//如果n是奇数的话，那么一定有一个0（也就是站在中间），2,2,4,4,...,(n-1),(n-1)；
//满足的话方案数为2^(n-1)/2 
//如果n是偶数的话，那么一定有1,1,3,3,5,5,n-1,n-1,满足的话方案数为2^n/2
//不满足以上条件则为0； 
//WA了四个点 

#include <iostream>
#include <cmath>
using namespace std;
int mod=1e9+7;
typedef long long LL;
const int N=1e5+10;
int n, b[N];
int qmi(int a, int k,int p){
    int res=1;
    while(k){
        if(k&1) res=(LL)res*a%p;
        k>>=1;
        a=(LL)a*a%p;
    }
    return res;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		b[x]++;
	}
	
	if(n==1){
		if(b[1]!=0) cout<<0;
		else cout<<1;
		return 0;	
	} 
	
	if(n%2==0){
		bool is_ok=true;
		for(int i=0;i<=n-1;i++)
		{
			if(i%2==0)
			{
				if(b[i]!=0){
					is_ok=false;
					break;	
				}	
			}
			else{
				if(b[i]!=2){
					is_ok=false;
					break;	
				}
			} 
		}
		if(!is_ok) cout<<0;
		else cout<<qmi(2,n/2,mod);
	}else{
		bool is_ok=true;
		for(int i=0;i<=n-1;i++)
		{
			if(i==0){
				if(b[i]!=1){
					is_ok=false;
					break;
				}
			}
			else{
				if(i%2==0){
					if(b[i]!=2){
						is_ok=false;
						break;
					}
				}else{
					if(b[i]!=0){
						is_ok=false;
						break;
					}
				}
			}
		}
		if(!is_ok) cout<<0;
		else cout<<qmi(2,(n-1)/2,mod);
	}
	return 0;
}
