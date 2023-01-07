#include<bits/stdc++.h>
#define M 1000
using namespace std;

bool mrk[M];

void sieve(int n)
{
    int i,j;
    mrk[0]= mrk[1]= true;

    for(i=4; i<=n; i+=2)
    {
        mrk[i] = true;
    }

    for(i=3; i*i<=n; i+=2)
    {
        if(mrk[i]==false)
        {
            for(j=i*i; j<=n; j+=2*i)
            {
                mrk[j] = true;
            }
        }
    }

    for(i=2; i<=n; i++)
    {
        if(mrk[i]==false)
            cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    sieve(M);
}
