#include<cstdio>
int ans,w=1e9;
char o[5],lst;
int main(){
	while(w!=1){
		printf("? %d\n",w),fflush(stdout),scanf("%s",o);
		if(*o=='Y'){
			printf("? %d\n",w-1),fflush(stdout),scanf("%s",o);
			if(*o=='N'||lst=='N')break;
		}
		lst=*o;
		w/=10;
	}
	if(w==1e9){printf("! %d\n",w),fflush(stdout);return 0;}
	if(w==1){
		for(int i=1;i<10;++i){
			printf("? %d0\n",i),fflush(stdout),scanf("%s",o);
			if(*o=='Y'){printf("! %d\n",i),fflush(stdout);return 0;}
		}
	}else{
		for(int i=1;i<10;++i){
			printf("? %d\n",i),fflush(stdout),scanf("%s",o);
			if(*o=='N')break;
			ans=i*w;
		}
		for(w/=10;w;w/=10){
			int l=0,r=9,s=0;
			while(l<=r){
				const int mid=l+r>>1;
				printf("? %lld\n",(ans+mid*w+w)*10LL-1);
				fflush(stdout),scanf("%s",o);
				if(*o=='N')l=mid+1;else r=(s=mid)-1;
			}
			ans+=s*w;
		}
	}
	printf("! %d\n",ans),fflush(stdout);
	return 0;
}