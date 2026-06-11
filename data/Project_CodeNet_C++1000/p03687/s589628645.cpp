#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>

using namespace std;
typedef long long ll;

int Calc(char alphabet, int FirstN, char s[]){
		while(true){
		int N = strlen(s);
		
		// ループ抜け判定
		bool AllSame = true;
		for(int i = 0; i < N-1; i++){
			if(s[i] != s[i+1]){
				AllSame = false;
			}
		}
		
		if(AllSame){
			return FirstN - N;
			break;
		}
		
		// 文字列変形処理
		char newS[101];
		bool skiped = false;
		for(int i = 0; i < N; i++){
			if(skiped){
				if(s[i] == alphabet || s[i-1] == alphabet){
					newS[i-1] = alphabet;
				}else{
					newS[i-1] = s[i];
				}
			}
			else{
				if(s[i] == alphabet || (i < N-1 && s[i+1] == alphabet)){
					newS[i] = alphabet;
				}else{
					skiped = true;
				}
			}
		}
		newS[N-1] = '\0';
		
		strcpy(s, newS);
	}
}

int main()
{
	char s[101];
	cin >> s;
	
	int N = strlen(s);
	
	int ans = 999;
	for(int i = 0; i < 26; i++){
		char S[101];
		strcpy(S, s);
		int count = Calc(char(i+97), N, S);
		if(count < ans){
			ans = count;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
