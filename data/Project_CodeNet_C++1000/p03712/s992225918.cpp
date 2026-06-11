#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  	int H, W;
  	cin >> H >> W;
    for(int i=0; i<W+2; i++){
    	cout << "#" ;
    }
  	cout << endl;
    vector<string> A(H);
    for (int i=0; i<H; i++){
    	cin >> A[i];
    }
    for (int i=0; i<H; i++){
  	cout << "#" << A[i] << "#" << endl;
    }
  	for(int i=0; i<W+2; i++){
    	cout << "#" ;
    }
  	cout << endl;
}