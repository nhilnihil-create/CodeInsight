#include<iostream>
using namespace std;
char a[16], b[16] = {'C', 'O', 'D', 'E', 'F', 'E', 'S', 'T', 'I', 'V', 'A', 'L', '2', '0', '1', '6'};//直接字符数组走一波，后面比较方便
int ans;
int main()
{
    cin >> a;
    for(int i = 0; i < 16; i ++){
        if(a[i] != b[i]) ans ++;
    }
    cout << ans << endl;
    return 0;
}