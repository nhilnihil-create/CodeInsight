#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9+7;
int n, a[100001], b[100001], cnt[100001];
int FF(int start, int num){
    return max(num-(start+1)/2, 0);
}

bool meet(int p1, int p2, int num){
    return (p2-2*(num-1)) <= (p1+1);
}

struct Elem{
    int place, num;
    Elem(int place, int num){
		this->place=place;
		this->num=num;
	}
};

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
		scanf("%d", &a[i]);

	vector<Elem> V;
	V.push_back(Elem(a[1], 1));

	for(int i=2; i<=n; i++){
		V.push_back(Elem(a[i], 1));
		while(V.size()>=2){
			unsigned int p=V.size()-2;
			unsigned int q=V.size()-1;

			if(meet(V[p].place, V[q].place, V[q].num)){
				V[p].place=V[q].place;
				V[p].num+=V[q].num;
				V.pop_back();
			}
			else break;
		}
		/*for(const Elem &e:V){
			printf("(%d, %d)\n", e.place, e.num);
		}*/
		b[i]=FF(V[0].place, V[0].num);
		//printf("b[%d]:%d\n\n", i, b[i]);

	}

	cnt[1]++;
	for(int i=2; i<=n; i++)
		cnt[b[i-1]+1]++;

	long long ans = 1;
	int sum=0;
	for(int i=1; i<=n; i++){
		sum+=cnt[i];
		ans=ans*sum%mod;
		sum--;
	}
	printf("%lld", ans);
	return 0;
}
