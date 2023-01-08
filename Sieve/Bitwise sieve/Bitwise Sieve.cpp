#include<bits/stdc++.h>

using namespace std;
const int N = 100;
int status[N/32];

bool check(int N, int pos)
{
    return (bool)(N&(1<<pos));
}

int sett(int N, int pos)
{
    N = N | (1<<pos);
    return N;
}

void bitwise_sieve(int N)
{
    for(int i = 3; i*i<=N; i+=2)
    {
        if(check(status[i/32], i%32)==0)
        {
            for(int j = i*i; j<=N; j+=2*i)
            {
                status[j/32] = sett(status[j/32],j%32);
            }
        }
    }

    cout<<"2 ";
    for(int i = 3; i<=N; i+=2)
    {
        if(check(status[i/32],i%32)==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    bitwise_sieve(N);
}
