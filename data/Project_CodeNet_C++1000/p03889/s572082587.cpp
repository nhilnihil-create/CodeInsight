#include<bits/stdc++.h>

std::string s1, s2;

int main()
{
	std::cin >> s1;
	s2 = s1;
	std::reverse(s2.begin(), s2.end());
	for(int i = 0; i < s2.size(); i ++)
	{
		if(s2[i] == 'b') s2[i] = 'd';
		else if(s2[i] == 'd') s2[i] = 'b';
		else if(s2[i] == 'p') s2[i] = 'q';
		else if(s2[i] == 'q') s2[i] = 'p';  
	}
//	std::cout << s1 << " " << s2 << "\n"; 
	if(s1 == s2)
	{
		printf("Yes");
	}
	else 
	{
		printf("No");
	}
	return 0;
}