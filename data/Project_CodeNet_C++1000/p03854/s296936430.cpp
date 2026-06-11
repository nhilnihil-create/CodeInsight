// ABC049C.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

string stringList[4] = {"maerd","remaerd","esare","resare"};

int main()
{
	string str;
	cin>>str;
	string reverseStr;
	int n = str.length();
	for(int i = n-1; i >= 0; i--){
		reverseStr.push_back(str[i]);
	}
	bool canMake = true;
	while(reverseStr.length() != 0){
		if( reverseStr.length() < 5){
			canMake = false;
			break;
		}
		
		rep(i,4){
			if( reverseStr == stringList[i]){
				canMake = true;
				break;
			}
		}
		bool match = false;
		if(reverseStr.length() >= 5){
			rep(i,4){
				if(reverseStr.substr(0,5) == stringList[i]){
					reverseStr = reverseStr.substr(5,reverseStr.length()-5);
					match = true;
				}
			}
		}
		if(reverseStr.length() >= 6){
			rep(i,4){
				if(reverseStr.substr(0,6) == stringList[i]){
					reverseStr = reverseStr.substr(6,reverseStr.length()-6);
					match = true;
				}
			}
		}
		if(reverseStr.length() >= 7){
			rep(i,4){
				if(reverseStr.substr(0,7) == stringList[i]){
					reverseStr = reverseStr.substr(7,reverseStr.length()-7);
					match = true;
				}
			}
		}
		if(match == false){
			canMake = false;
			break;
		}
		
	}
	if( canMake == true){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}

