#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 1010;

int lena,lenb,tr;
string A,B;

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	tr=-1;
	cin>>A;
	cin>>B;
	
	lena=A.size(),lenb=B.size();
	
	if(lena > lenb){
		tr = 1;
	}else if(lena < lenb){
		tr = 0;
	}else{
		int t=-1;
		for(int i=0;i<lena;i++){
			if(A[i] < B[i]){
				t = 0;
				break;
			}else if(A[i] > B[i]) {
				t = 1;	
				break;
			}else{
				continue;
			}
		}
		if(t==1) {
			tr = 1;
		}else if(t==0){
			tr = 0;
		}
	}
	if(tr==0){
		printf("LESS\n");
	}else if(tr==1){
		printf("GREATER\n");
	}else{
		printf("EQUAL\n");
	}

	return 0;
}
