#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nin(n);
	for(int i=0; i<n; i++){
    	cin >> nin.at(i);
    }
	sort(nin.begin(), nin.end());
	int f = 0;
	long anser = 1;
	if(n%2 == 0){
    	for(int i=0; i<n/2; i++){
        	if(!(nin.at(i*2) == i*2+1 && nin.at(i*2+1) == i*2+1)){
            	f = 1;
            	break;
            }
        }
    	if(f == 0){
        	for(int i=0; i<n/2; i++){
            	anser *= 2;
            	if(anser >= 1000000007){
                	anser = anser%1000000007;
                }
            }
            cout << anser << endl;
        }else{
            cout << 0 << endl;
        }
    }else{
    	if(nin.at(0) != 0){
        	f = 1;
        }
    	for(int i=0; i<(n-1)/2; i++){
        	if(!(nin.at(i*2+1) == i*2+2 && nin.at(i*2+2) == i*2+2)){
            	f = 1;
            	break;
            }
        }
        if(f == 0){
        	for(int i=0; i<(n-1)/2; i++){
            	anser *= 2;
            	if(anser >= 1000000007){
                	anser = anser%1000000007;
                }
            }
            cout << anser << endl;
        }else{
            cout << 0 << endl;
        }
    }
}