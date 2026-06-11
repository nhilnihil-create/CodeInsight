#include<iostream>
#include<cstring>
using namespace std;
const int N = 2*1e5+10;
char str[N];
int pre[N];
int r,l,length, ans;
bool jud;

int main()
{
    scanf("%s",str);
    length = strlen(str);
    for(int i = 0; i < length; i++)pre[i] = i - 1;
    r = 1;
    while(r < length)
    {
        jud = false;
        while(str[l]=='S' && str[r]=='T')
        {
            ans += 2;
            if(pre[l] < 0 || r + 1 > length)
            {
                jud = true;
                break;
            }
            l = pre[l];
            r++;
            pre[r] = l;
        }
        if(pre[l] < 0 && jud)l = r + 1, r += 2;
        else l = r, r++;
    }
    printf("%d",length - ans);
    return 0;
}