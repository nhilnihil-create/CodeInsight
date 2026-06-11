#include <cstring>
#include <cstdio>
using namespace std;
char ch[15];
int len,base;
long long ans,sum,cnt;
int main(){
	scanf("%s",ch);
	len=strlen(ch);
	base=1<<(len-1);
	for(int i=0;i<base;++i){
		int t=i<<1;
		sum=0;
		cnt=0;
		for(int j=0;j<len;++j){
			if(t&1){
				sum+=cnt;
				cnt=ch[j]-'0';
			}else{
				cnt=cnt*10+ch[j]-'0';
			}
			t/=2;
		}
		sum+=cnt;
		ans+=sum;
	}
	printf("%lld\n",ans);
	return 0;
}