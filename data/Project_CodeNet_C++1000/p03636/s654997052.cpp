/*
 * main.cpp
 *
 *  Created on: 2020/04/07
 *      Author: SkAaO
 */

#include <iostream>

using namespace std;

int main(){
	string S;
	cin >> S;

	int m_len = (int)S.size() - 2;
	int len = (int)S.size();

	char first = S.at(0);
	char tale = S.at(len-1);

	printf("%c%d%c", first, m_len, tale);

	return 0;
}


