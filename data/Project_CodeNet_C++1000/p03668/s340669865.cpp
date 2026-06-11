#include <cstdio>

using namespace std;

typedef long long int64;

struct IO_Tp
{
	bool is_digit(const char ch)
	{
		return '0' <= ch && ch <= '9';
	}
	
	IO_Tp& operator>>(int& res)
	{
		res = 0;
		static char ch;
		while (ch = getchar(), !is_digit(ch))
			;
		do
			(res *= 10) += ch & 15;
		while (ch = getchar(), is_digit(ch));
		return *this;
	}
} IO;

const int Max_N(100005);

int N, Total(1), Head[Max_N], Next[Max_N * 2], To[Max_N * 2];

int sg(const int v, const int p = 0)
{
	int res(0);
	for (int e(Head[v]); e; e = Next[e])
		if (To[e] != p)
			res ^= sg(To[e], v) + 1;
	return res;
}

int main(int argc, char** argv)
{
	IO >> N;
	
	for (int i(1), v, w; i != N; ++i)
	{
		IO >> v >> w;
		Next[Total] = Head[v], To[Total] = w, Head[v] = Total++;
		Next[Total] = Head[w], To[Total] = v, Head[w] = Total++;
	}
	
	puts(sg(1) ? "Alice" : "Bob");
	
	return 0;
}