/*input
*/
#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0, c = getchar();
	for(; !(c > 47 && c < 58); c = getchar());
	for(; (c > 47 && c < 58); c = getchar()) x = x * 10 + c - 48;
	return x;
}

int a[100005];

int main(){
    int n = read();
	for(int i = 0; i < n; a[i ++] = read());
	sort(a, a + n, greater<int>());

	int pos = 0;
	for(int i = 0; i < n; ++ i)
		if(a[i] > i) pos = i;

    if((a[pos] - pos) % 2 == 0) return puts("First"), 0;

	for(int i = pos + 1; i <= n; ++ i)
		if(a[i] <= pos) {
            if((i - pos) % 2 == 0) return puts("First"), 0;
            break;
		}

    puts("Second");
}
