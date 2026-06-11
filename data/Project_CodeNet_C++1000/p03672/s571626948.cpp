#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 1000010;

int n,ans;
string s;

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	cin>>s;
	n = s.size();
	for(int i=1;i<n/2;i++){
		for(int j=i;j<=i+i-1;j++){
			int tr=1;
			for(int k=0;k<i;k++){
				if(s[k]!=s[k+i]){
					tr=0; break;
				}
			}
			if(tr) ans=i;
		}
	}
	
	printf("%d\n",ans*2);
	
	return 0;
}