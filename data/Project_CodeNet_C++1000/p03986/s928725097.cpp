#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
    string s; //获取输入字符
    cin >> s;
    int totalsize = s.size();
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'S') { //找到一个S
                num++; //S计数
        }
        if (s[i] == 'T') { //找到一个T
            if (num > 0) { //有S与之匹配
                num--; //统计
                totalsize -= 2;
            }
        }
    }
    cout << totalsize << endl; //输出结果
}