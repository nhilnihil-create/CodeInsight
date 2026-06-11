#include <bits/stdc++.h>

using namespace std;

long long options1[100010];
long long options2[100010];
long long moduo = 1e9 + 7;

long long fast_pow(long long n,long long k)
{
    if(k == 0) return 1;
    else
    {
        long long a = fast_pow(n,k/2)%moduo;
        if(k%2 == 0) return (a*a)%moduo;
        else return (((n*a)%moduo)*a)%moduo;
    }
}

void generate_opt1(int n,int m,int h,int w)
{
    options1[1] = 1;
    long long k = 2; /// bilo je ranije 1
    while(k <= n-h)
    {
        long long inverz = fast_pow(k-1,moduo-2)%moduo;
        /*if(options1[k] < 0)
        {
            cout<<options2[k]<<" "<<k<<" "<<inverz<<" __1"<<endl;
            system("PAUSE");
        }*/
        inverz%=moduo;
        options1[k] = (((options1[k-1]*(w+ k-1 +1-2))%moduo)*inverz)%moduo;
        options1[k] %= moduo;
        k++;
    }

    /*for(int i = 1; i <= n-h; i++)
    {
        cout<<"options1["<<i<<"]: "<<options1[i]<<endl;
    }*/
}

long long factoriel(long long a) /// treba da mod
{
    long long ret = 1;
    for(long long i = 1; i <= a; i++)
    {
        ret*=i;
        ret%=moduo;
    }

    return ret%moduo;
}

long long calculate_A_nad_B(long long a, long long b)
{
    if(a == b) return 1;
    long long ret = 0;
    long long pom1,pom2,pom3;
    //cout<<"a b "<<a<<" "<<b<<endl;
    pom1 = factoriel(a)%moduo; pom2 = factoriel(b)%moduo; pom3 = factoriel(a-b)%moduo; /// svuda si dodao %moduo
    //cout<<pom1<<" "<<pom2<<" "<<pom3<<endl;
    //cout<<"long_long_max"<<LONG_LONG_MAX<<endl;
    //ret = (pom1%moduo)*(fast_pow(pom2,moduo-2)%moduo)*(fast_pow(pom3,moduo-2)%moduo)%moduo; ///mnozenje inverzima zbog modula
    long long x = fast_pow(pom2,moduo-2)%moduo;
    long long y = fast_pow(pom3,moduo-2)%moduo;
    ret = (((pom1*x)%moduo)*y)%moduo;
    //cout<<ret<<endl;

    return ret%moduo;
}

void generate_opt2(int n,int m,int h,int w)
{
    long long d = m-w;
    long long k = h+1;
    long long br = k - 1;
    options2[k-br] = calculate_A_nad_B(k+d-2,k-1)%moduo; /// promenios sa opt od 1 na opt od k
    //cout<<"options2[1]: "<<options2[1]<<endl;

    k++; /// ovo si dodao
    while(k <= n)
    {
        //cout<<"k: "<<k<<endl;
        long long inverz = fast_pow(k-1,moduo-2)%moduo; ///umesto ka promenio si na k -1
        inverz%=moduo;
        //cout<<"k inverz1: "<<k<<" "<<inverz<<endl;
        options2[k -br] = (((options2[k-1 -br]*(d+ k-1 +1-2))%moduo)*inverz)%moduo; /// dodo si -br da bih ubacivao u niz pocevsi od indexa 1 , a ne od indexa k sto moze biti veliki br
        options2[k -br]%=moduo;
        /*if(options2[k - br] < 0)
        {
            cout<<options2[k - br]<<" "<<k<<" "<<inverz<<" __2"<<endl;
            system("PAUSE");
        }*/
        k++;
        //cout << "uso2"<<endl;
    }

    //for(int i = n-h; i>= 1; i--)
        //cout<<"options2["<<i<<"]: "<<options2[i]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,h,w;
    cin>> n >> m >>h >> w;
    //cout<<fast_pow(n,m);

    generate_opt1(n,m,h,w);
    generate_opt2(n,m,h,w);

    long long res = 0;
    long long d = n-h;

    for(int i = 1; i <= d; i++)
    {
        long long pom1 = options1[i] % moduo;
        long long pom2 = options2[d-i+1] % moduo;
        long long pom3 = (pom1 * pom2) % moduo;
        res+= pom3;
        res%=moduo;
    }

    cout<< res;

    return 0;
}
