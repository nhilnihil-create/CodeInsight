#include<cstdio>
using namespace std;

int main()
{
    int l=0,Ascore=0,Bscore=0;
    char ch;
    while((ch=getchar())!='\n')
    {
        if(ch=='p')
            Ascore++;
        l++;
    }
    Bscore=l>>1;
    printf("%d\n",Bscore-Ascore);
    return 0;
}
