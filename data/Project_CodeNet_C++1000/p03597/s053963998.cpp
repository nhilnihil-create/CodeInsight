#include <bits/stdc++.h>
using namespace std;

int main() {
	int length,white,black,area;
    cin >> length >> white;
    area = length * length;
    black = area - white;
    cout << black << endl;
}