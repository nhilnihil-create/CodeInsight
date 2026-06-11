//
//  main.cpp
//  ProblemSolving
//
//  Created by Mac mini on 1/7/20.
//  Copyright © 2020 Mac mini. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	stack<char> A, B, C;
	string a, b, c;
	
	cin >> a >> b >> c;
	
	for(int i = a.size() - 1; i >= 0; i--) A.push(a[i]);
	for(int i = b.size() - 1; i >= 0; i--) B.push(b[i]);
	for(int i = c.size() - 1; i >= 0; i--) C.push(c[i]);
	
	int nextMove = 1;
	
	while(1) {
		char x;
		if(nextMove == 1) {
			if(A.empty()) {
				return cout << "A", 0;
			}
			x = A.top(); A.pop();
			nextMove = x == 'a' ? 1 : (x == 'b' ? 2 : 3);
		} else if (nextMove == 2) {
			if(B.empty()) {
				return cout << "B", 0;
			}
			x = B.top(); B.pop();
			nextMove = x == 'a' ? 1 : (x == 'b' ? 2 : 3);
		} else {
			if(C.empty()) {
				return cout << "C", 0;
			}
			x = C.top(); C.pop();
			nextMove = x == 'a' ? 1 : (x == 'b' ? 2 : 3);
		}
	}
}
