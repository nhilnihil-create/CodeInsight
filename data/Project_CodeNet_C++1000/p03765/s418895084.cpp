#include <iostream>
#include <vector>
using namespace std;

int main() {
    int q;
    vector<int> sum[2];
    for(int i=0;i<2;i++){
        int len;
        string s;
        cin >> s;
        len = s.length();
        sum[i].assign(len+1, 0);
        for(int j=0;j<len;j++){
            int res = sum[i][j];
            if(s[j] == 'A')res++;
            else res += 2;
            sum[i][j+1] = res % 3;
        }
    }
    cin >> q;
    for(int i=0;i<q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int p = sum[0][b] - sum[0][a-1] + 3;
        int q = sum[1][d] - sum[1][c-1] + 3;
        if(p%3 == q%3)puts("YES");
        else puts("NO");
    }
	return 0;
}