#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{

#if !ONLINE_JUDGE

	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w" , stdout);

#endif

	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;


	int v = ty - sy;
	int h = tx - sx;

	map<char, char>op;


	op['U'] = 'D';
	op['D'] = 'U';
	op['R'] = 'L';
	op['L'] = 'R';



	string s1u = "";
	for (int i = 0; i < v; i++)
	{
		s1u = s1u + "U";
	}
	for (int i = 0; i < h; i++)
	{
		s1u = s1u + "R";
	}

	string s1d = "";

	for (int i = 0; i < s1u.size(); ++i)
	{
		if (s1u[i] == 'U')
		{
			s1d = s1d + 'D';
		}
		else if (s1u[i] == 'R')
		{
			s1d = s1d + 'L';
		}
	}


	v++;
	h++;

	string s2u = "L";
	for (int i = 0; i < v; i++)
	{
		s2u = s2u + "U";
	}
	for (int i = 0; i < h; i++)
	{
		s2u = s2u + "R";
	}
	s2u += 'D';

	string s2d = "";

	for (int i = 0; i < s2u.size(); ++i)
	{
		if (s2u[i] == 'U')
		{
			s2d = s2d + 'D';
		}
		else if (s2u[i] == 'R')
		{
			s2d = s2d + 'L';
		}
		else if (s2u[i] == 'L')
		{
			s2d = s2d + 'R';
		}
		else if (s2u[i] == 'D')
		{
			s2d = s2d + 'U';
		}

	}


	cout << s1u + s1d + s2u + s2d << endl;




	return 0;
}