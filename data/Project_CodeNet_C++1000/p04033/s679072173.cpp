# include <iostream>
using namespace std;

int a;
int b;
int product=1;

int main()
{
    cin>>a>>b;

    for (int i=a; i<=b; i++)
    {
        if (i<0)
        {
            product=product*-1;
        }

        if (i==0)
        {
            cout<<"Zero"<<endl;
            return 0;
        }
    }

    if (product>0)
    {
        cout<<"Positive"<<endl;
    }

    else 
    {
        cout<<"Negative"<<endl;
    }
    //te
}