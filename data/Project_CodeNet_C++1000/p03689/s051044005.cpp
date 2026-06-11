/*
首先搞定一个性质，就是假如小矩形横着或者竖着的长度小于等于大矩形的1/2肯定不行， 因为两个负权值的合并起来也一定是负权值，
这样的话就判断了不可行的情况， 然后考虑这样相当于形成了一个横竖十字交
将负数放在交上肯定会更合适
所以直接在十字的某个元素放-数就好了

结果发现交不成十字的也要考虑， 因为这样也可能是更优的,那么贪心来放， 第一个不能放的放上

发现更能转换成一般模型， 在刚要过界的地方看看是否合适， 这样先弄再判断所有权值 再输出正误

发现还忽略一个问题， 有时候不选择1会更优 ， 其他数字都加一的情况下， 这个可以减去一部分，使得总权值更大QWQ

*/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
#define ll long long
#define M 550
using namespace std;
int read() {
	int nm = 0, f = 1;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) nm = nm * 10 + c - '0';
	return nm * f;
}

ll a, b, c, d, ans, s1, s2;
int note[M][M];
int main() {
	a = read(), b = read(), c = read(), d = read();
	int ct =1000000000 / (c * d);
	int op = c * d - 1;
	for(int i = 1; i <= a; i++) {
		for(int j = 1; j <= b; j++) {
			if((i % c == 0) && (j % d == 0)) note[i][j] = op * ct * -1 - 1, s2++;
			else note[i][j] = ct, s1++;
			ans += note[i][j];
		}
	}
	if(ans <= 0) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";

	for(int i = 1; i <= a; i++) {
		for(int j = 1; j <= b; j++) {
			cout << note[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}