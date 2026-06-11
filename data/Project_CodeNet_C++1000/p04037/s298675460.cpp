#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int n, a[N];//, sg[N][N];

// int mex(set<int> st){
//     for(int i = 0; ; i++) if(st.find(i) == st.end()) return i;
// }
// int SG(int x, int y){
//     return mex(set<int>{sg[x][y + 1], sg[x + 1][y]});
// }

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n); reverse(a + 1, a + 1 + n);
    for (int i=0;i<=n;i++)
		if (i+1>a[i+1])
		{
			int r=i;
			while (a[r+1]==i) r++;
			puts((((a[i]-i)&1)||((r-i)&1))?"First":"Second");
			break;
		}
    return 0;
}