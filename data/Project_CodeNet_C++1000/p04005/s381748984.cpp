#include<cstdio>
using namespace std;

long long a=0,b=0,c=0;

int main(){
	scanf("%lld %lld %lld",&a,&b,&c);
	long long cha1=0,cha2=0,cha3=0;
	
	long long temp=a*b*(c/2)-a*b*(c-c/2);
	if(temp>0){cha1=temp;	}
	else{cha1=-temp;}
	
	temp=a*c*(b/2)-a*c*(b-b/2);
	if(temp>0){cha2=temp;	}
	else{cha2=-temp;}
	
	temp=b*c*(a/2)-b*c*(a-a/2);
	if(temp>0){cha3=temp;	}
	else{cha3=-temp;}
	
	long long min=0;
	if(cha1<cha2){min=cha1;}
	else{min=cha2;	}
	if(min>cha3){min=cha3;	}
	printf("%lld\n",min);
	return 0;
} 