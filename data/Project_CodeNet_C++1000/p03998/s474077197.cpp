#include<cstdio>
#include<queue>
using namespace std;

queue<char>q[3];

void Scan(int n)
{
    char ch;
    while((ch=getchar())!='\n')
    {
        q[n].push(ch);
    }
}

int main()
{
    Scan(0);
    Scan(1);
    Scan(2);
    int k=0;
    while(q[k].size())
    {
        char ch=q[k].front();
        q[k].pop();
        k=ch-'a';
    }
    printf("%c\n",k+'A');
    return 0;
}
