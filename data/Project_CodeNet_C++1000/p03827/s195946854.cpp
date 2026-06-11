#include <bits/stdc++.h>
using namespace std;

int main() {
	 int N;
	 string S;
	 cin >> N >> S;
	 int score=0, max_score=0;
	 for (int i=0; i<N; i++){
	     if (S.at(i)=='I') score++;
	     if (S.at(i)=='D') score--;
	     max_score=max(max_score, score);
	 }
	 cout << max_score << endl;
}