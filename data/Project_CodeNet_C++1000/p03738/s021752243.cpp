#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#define fore(i,x,y) for(long long i=x;i<y;i++)
typedef long long ll;
using namespace std;
int main()
{
	string s,t;
	cin>>s>>t;
	if(s.size()>t.size()){
		cout<<"GREATER"<<endl;
	}
	else if(s.size()<t.size()){
		cout<<"LESS"<<endl;
	}
	else if(s==t){
		cout<<"EQUAL"<<endl;
	}
	else{
		if(s>t){
			cout<<"GREATER"<<endl;
		}
		else{
			cout<<"LESS"<<endl;
		}
	}
}