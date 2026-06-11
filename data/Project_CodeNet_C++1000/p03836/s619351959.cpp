#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

int main(int argc, char* argv[]){
	int sx, sy, tx, ty;
	int dx, dy;

	cin >> sx >> sy >> tx >> ty;

	dx = abs(sx - tx);
	dy = abs(sy - ty);

	for(int i=0; i<dx; i++) putchar('R');
	for(int i=0; i<dy; i++) putchar('U');
	for(int i=0; i<dx; i++) putchar('L');
	for(int i=0; i<dy; i++) putchar('D');
	putchar('D');
	for(int i=0; i<dx+1; i++) putchar('R');
	for(int i=0; i<dy+1; i++) putchar('U');
	putchar('L');
	putchar('U');
	for(int i=0; i<dx+1; i++) putchar('L');
	for(int i=0; i<dy+1; i++) putchar('D');
	putchar('R');
	putchar('\n');

	return 0;

}
