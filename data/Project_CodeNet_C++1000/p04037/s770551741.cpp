#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;

int a[N], n;

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", a + i);
	sort(a, a + n);
	reverse(a, a + n);
	int pivot = 0;
	while(a[pivot] > pivot + 1)
		pivot++;
	int ans = 0;
	if(a[pivot] == pivot + 1){
		if(a[pivot + 1] == a[pivot]){
			int jos = pivot;
			while(a[pivot] == a[jos])
				jos++;
			jos--;
			ans = (jos - pivot) % 2;			
		}
		else{
			ans = 0;
		}
	}
	else{
		if(a[pivot - 1] == a[pivot]){
			int jos = pivot;
			while(a[pivot] == a[jos])
				jos++;
			jos--;
			ans = (jos - pivot + 1) % 2;
		}
		else{
			ans = (a[pivot - 1] - pivot) % 2;
			if(pivot == a[pivot]){
				int jos = pivot;
				while(a[pivot] == a[jos])
					jos++;
				jos--;
				ans |= (jos - pivot + 1) % 2;	
			}
		}
	}
	printf(ans ? "First\n" : "Second\n");
}