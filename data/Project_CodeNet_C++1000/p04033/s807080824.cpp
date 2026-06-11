#include <cstdio>

int l, r;

int main(){
	std::scanf("%d%d", &l, &r);
	if(l <= 0 && r >= 0)
		return std::puts("Zero"), 0;
	if(l > 0)
		return std::puts("Positive"), 0;
	else
		return std::puts((r - l + 1) & 1 ? "Negative" : "Positive"), 0;
}