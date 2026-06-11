#include<iostream>

int main(){
	int A, B;
	std::cin >> A >> B;

	A = A == 1 ? 100 : A;
	B = B == 1 ? 100 : B;

	auto ans = A == B ? "Draw" : A > B ? "Alice" : "Bob";
	std::cout << ans << "\n";

	return 0;
}