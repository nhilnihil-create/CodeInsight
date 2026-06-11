#include <iostream>
int main() {
	int n, ans = 0;
	int kasan = 0;
	std::cin >> n;
	while(ans<n){
		kasan++;
		ans += kasan;	
	}
	std::cout << kasan << std::endl;


}