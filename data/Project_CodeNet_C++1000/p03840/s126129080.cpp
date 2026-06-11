#include "bits/stdc++.h"
using namespace std;

int main() {
	long long Ai, Ao, At, Aj, Al, As, Az, count1 = 0, count2 = 0;
	cin >> Ai >> Ao >> At >> Aj >> Al >> As >> Az;
	count1 = Ai - Ai % 2 + Aj - Aj % 2 + Al - Al % 2;
	if (Ai > 0 && Aj > 0 && Al > 0) {
		Ai--, Aj--, Al--;
		count2 = Ai - Ai % 2 + Aj - Aj % 2 + Al - Al % 2 + 3;
	}
	cout << max(count1, count2) + Ao;
}