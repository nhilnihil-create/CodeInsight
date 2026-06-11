#include <iostream>
using namespace std;
int main()
{
    long long numa,x;
    cin >> numa >> x;
    if(x<=numa/2){
        x = numa-x;
    }
    long long numb = numa;
    long long ans = 0;

    long fin;

    ans += x;
    numb -= x;
    x= numb;
    ans += ((numa/x)*2-1)*x;
    numa %= x;
    if(numa<numb){
        swap(numa,numb);
    }
    fin = x;
    x = numb;
    if(x == 0){
        goto ANSWER;
    }

    for(;;){
        ans += (numa/x)*2*x;
        numa %= x;
        if(numa<numb){
            swap(numa,numb);
        }
        fin = x;
        x = numb;
        if(x==0){
            break;
        }
    }

ANSWER:
    ans -= fin;
    cout << ans << endl;

    return 0;

}