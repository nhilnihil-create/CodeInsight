#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b, a%b);
}

int main()
{
	int n;
	scanf("%d", &n);
	ll a[100000], sum=0;
	for(int i=0; i<n; i++){
		scanf("%lld", &a[i]);
		sum+=a[i];
	}
	if(n==1){
		if(sum==1){
			printf("Second\n");
		}else{
			printf("First\n");
		}
		return 0;
	}
	if(n%2==0){
		if(sum%2==0){
			printf("Second\n");
		}else{
			printf("First\n");
		}
		return 0;
	}
	if(sum%2==0){
		printf("First\n");
		return 0;
	}
	int c=0;
	while(1){
		int count=0, count1=0;
      ll sum1=0;
		for(int i=0; i<n; i++){
          if(a[i]==1){
            count1++;
            continue;
          }
          sum1+=a[i];
			if(a[i]%2!=0){
				count++;
				a[i]--;
			}
		}
      if((n-count1)%2==0){
        if((c+sum1)%2==0){
          printf("Second\n");
        }else{
          printf("First\n");
        }
        return 0;
      }
      if(sum1%2==0){
        if(c%2==0){
          printf("First\n");
        }else{
          printf("Second\n");
        }
        return 0;
      }
		if(count>1){
			if(c%2==0){
				printf("Second\n");
			}else{
				printf("First\n");
			}
			return 0;
		}
		ll g=a[0];
		for(int i=1; i<n; i++){
			g=gcd(g, a[i]);
		}
		for(int i=0; i<n; i++){
			a[i]/=g;
		}
		c++;
	}
	return 0;
}