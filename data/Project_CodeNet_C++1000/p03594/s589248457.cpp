#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;
#define Fill(a, b) memset(a, b, sizeof(a))
#define Debug(x) cout << #x << "=" << (x) << endl;
typedef long long LL;
const LL inf = 1LL << 61;
const LL mod = 1000000007;
#define DEBUG
#ifdef DEBUG
#endif
const int maxn = 510;

char mat1[maxn][maxn];
char mat2[2*maxn][2*maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    int h, w, d;
    scanf("%d%d%d", &h, &w, &d);
    for(int i = 1, f1 = 0; i < 2*maxn; i+=d, f1++)
    {
    	for(int j = 1, f2 = 0; j < 2*maxn; j+=d, f2++)
    	{
    		char ch;
    		if(f1%2)
    		{
    			if(f2%2)
    			{
    				ch = 'B';
    			}
    			else
    			{
    				ch = 'Y';
    			}
    		}
    		else
    		{
    			if(f2%2)
    			{
    				ch = 'R';
    			}
    			else
    			{
    				ch = 'G';
    			}
    		}
    		for(int r = i; r < min(i+d,2*maxn); r++)
    		{
    			for(int c = j; c < min(j+d,2*maxn); c++)
    			{
    				mat2[r][c] = ch;
    			}
    		}
    	}
    }
    /*
    cout << "mat2\n";
    for(int i = 1; i < h+w; i++)
    {
    	for(int j = 1; j < h+w; j++)cout << mat2[i][j];cout << endl;
    }
    */
	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= w; j++)
		{
			int x = w+i-j, y = i+j-1;
			mat1[i][j] = mat2[x][y];
		}
	}
	//cout << "mat1\n";
    for(int i = 1; i <= h; i++)
    {
    	for(int j = 1; j <= w; j++)
    	{
    		printf("%c", mat1[i][j]);
    	}
    	puts("");
    }
	






















    return 0;
}
