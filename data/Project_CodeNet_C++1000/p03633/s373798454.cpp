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

typedef long long LL;

LL GCD(LL x, LL y){
        LL r=0;
        if(x < y) swap(x, y);
        r = x % y;
        while(r!=0){
                x = y;
                y = r;
                r = x % y;
        }
        return y;
}

LL LCM(LL x, LL y){
        if(x < y) swap(x, y);
        return (x/GCD(x, y))*y;
}


int main(int argc, char* argv[]){
	int N;
	LL T[102] = {0};

	cin >> N;
	LL ans = 0;
	for(int i=1; i<=N; i++){
		cin >> T[i];
		if(i == 1){
			ans = T[1];
		}
		else{
			ans = LCM(ans, T[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
