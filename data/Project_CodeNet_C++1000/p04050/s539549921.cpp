#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 300010;

int n , m , a[N];


vector<int> odd,even,res;
int main() {
 //	freopen("input.txt","r",stdin);
 	scanf("%d%d",&n,&m);
 	for (int i = 0; i < m; ++i){
 		scanf("%d",&a[i]);
 		if(a[i]&1)
 			odd.push_back(a[i]);
 		else
 			even.push_back(a[i]);
 	}
 	if(odd.size() > 2){
 		puts("Impossible");
 	}else{
 		if(odd.size()){
 			res.push_back(odd.back());
 			odd.pop_back();
 		}
 		while(even.size()) res.push_back(even.back()),even.pop_back();
 		if(odd.size()){
 			res.push_back(odd.back());
 			odd.pop_back();
 		}
 		for (int i = 0; i < res.size(); ++i){
 			if(i)
 				printf(" ");
 			printf("%d",res[i]);
 		}
 		puts("");
 		if(res.size() == 1){
 			res.back()--;
 			res.push_back(1);
 		}else{
 			res[0]--;
 			res.back()++;
 		}
 		int cnt = 0;
 		for (int i = 0; i < res.size(); ++i){
 			if(res[i])
 				cnt++;
 		}
 		printf("%d\n",cnt);
 		cnt = 0;
 		for (int i = 0; i < res.size(); ++i){
 			if(cnt)
 				printf(" ");
 			if(res[i])
 				printf("%d",res[i]),cnt++;
 		}
 		puts("");
 	}
    return 0;
}