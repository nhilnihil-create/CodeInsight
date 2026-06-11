
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

std::vector<int> graph[100010];

int main(void)
{
	//変数の宣言
	int n,m;
	int a,b;
	int iti;
	static int route1[100010];
	static int route2[100010];
	static int come[100010];
	int route1len,route2len;

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	long int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	//データの読み込み
	
	scanf("%d %d",&n,&m);
	
	for(i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(i=0;i<100010;i++){
		come[i]=0;
	}

//	printf("nは%dです\n", n);
//	printf("データの読み込み終了\n");
	//実際の処理
	
	route1[0]=1;
	iti=1;
	j=0;
	come[1]=1;
	while(flag==0){
		flag=1;
		for(i=0;i<graph[iti].size();i++){
			if(come[graph[iti][i]]==0){
				come[graph[iti][i]]=1;
				iti=graph[iti][i];
				j++;
				route1[j]=iti;
				flag=0;
				break;
			}
		}
	}
	route1len=j+1;

	flag=0;
	route2[0]=1;
	iti=1;
	j=0;
	while(flag==0){
		flag=1;
		for(i=0;i<graph[iti].size();i++){
			if(come[graph[iti][i]]==0){
				come[graph[iti][i]]=1;
				iti=graph[iti][i];
				j++;
				route2[j]=iti;
				flag=0;
				break;
			}
		}
	}
	route2len=j+1;

	printf("%d\n",route1len+route2len-1);

	for(i=route1len-1;i>=0;i--){
		if(i!=route1len-1) printf(" ");
		printf("%d",route1[i]);
	}

	for(i=1;i<route2len;i++){
		printf(" %d",route2[i]);
	}


//	printf("計算部分終了\n");
	//出力
	
	
//	printf("結果の出力終了\n");
	
	return 0;
	
}

