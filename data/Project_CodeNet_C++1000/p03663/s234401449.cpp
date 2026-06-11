#include <bits/stdc++.h>

using namespace std;

int i,lb,ub;
string s;
long long v;
char s1[5];

bool check(string tmp, long long num){
	tmp += num + '0';
	while(tmp.size() < 11)
	tmp += '9';
	
	cout << "? " << tmp << endl;
	fflush(stdout);
	
	scanf("%s", s1);
	
	return s1[0] == 'Y';
}

char ask(long long num){
	printf("? %lld\n", num);
	fflush(stdout);
	
	scanf("%s", s1);
	
	return s1[0];
}

long long num(string s){
	long long tmp = 0;
	for(int ii = 0; ii < s.size(); ii++)
	tmp = tmp * 10 + s[ii] - '0';
	return tmp;
}

int main(){
	while(true){
		if(s.size() == 0){
			lb = 0;
			ub = 9;
		}
		else{
			lb = -1;
			ub = 9;
		}
		
		while(ub - lb > 1){
			int mid = (lb + ub) / 2;
			
			if(check(s, mid))
			ub = mid;
			else
			lb = mid;
		}
		
		s += ub + '0';
		v = num(s);
		
		bool all9 = 1;
		
		for(i = 0; i < s.size(); i++)
		all9 &= (s[i] == '9');
		
		if(all9){
			s[s.size() - 1]--;
			s += '0';
			int tmp = num(s);
			s.pop_back();
			s[s.size() - 1]++;
			
			if(ask(tmp) == 'N')
			break;
		}
		else if(ask(v + 1) == 'Y')
		break;
	}
	
	printf("! %lld\n", v);
}
