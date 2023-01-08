# Basic Sieve Function
### CODE:
```c++
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

```
### SOURCE:
[ShafaetPlanet](http://www.shafaetsplanet.com/?p=624)

# Linear Sieve
### CODE:
```c++
#include<bits/stdc++.h>
#define M 10
using namespace std;

vector<int>mp(M+1);
vector<int>pr;

void printmp()
{
    for(int i =0; i<M; i++)
    {
        cout<<i<<"-"<<mp[i]<<"   ";
    }
    cout<<endl;
}
void linear_sieve(int n)
{
    int i,j;
    for(i=2; i<n; i++)
    {
        if(mp[i]==0)
        {
            mp[i] = i;
            pr.push_back(i);
        }

        printmp();

        for(j=0; i*pr[j]<=n && pr[j]<=mp[i] && j<pr.size(); j++)
        {
            mp[i*pr[j]] = pr[j];
        }
    }

    for(i=0; i<pr.size(); i++)
    {
        cout<<pr[i]<< " "<<endl;
    }
    cout<<endl;
}

int main()
{
    linear_sieve(M);
}

```
### SOURCE:
[AlgorithmsForCP](https://cp-algorithms.com/algebra/prime-sieve-linear.html?fbclid=IwAR3ZZnXTHnqyN9q6030LdCAnQrX7ifm-U-Lm74rZbeBbzN7DTRDnC1mpUmI)  
[GreeksForGreeks](https://www.geeksforgeeks.org/sieve-eratosthenes-0n-time-complexity/)  

# Bitwise Sieve
### CODE:
```c++
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
    return 0;
}

```
### SOURCE:
[ShafaetPlanet](http://www.shafaetsplanet.com/?p=855)  


# Segmented Sieve
### CODE:
```c++
#include<bits/stdc++.h>
#define M 1000
#define ll long long
using namespace std;

vector<int>prm;
bool mrk[M];

void sieve(int n)
{
    ll i,j;
    mrk[0]=mrk[1]=true;

    prm.push_back(2);
    for(i=4; i<=n; i+=2)
    {
        mrk[i] = true;
    }

    for(i=3; i*i<=n; i+=2)
    {
        if(mrk[i]==false)
        {
            prm.push_back(i);
            for(j=i*i; j<=n; j+=2*i)
            {
                mrk[j] = true;
            }
        }
    }
}

void segmented_sieve(int L, int R)
{
    bool isprm[R-L+1];

    for(ll i=0; i<=R-L; i++)
    {
        isprm[i]=true;
    }

    if(L==1){
        isprm[0] = false;
    }

    for(ll i=0; prm[i]*prm[i]<=R; i++)
    {
        ll curp = prm[i];
        ll base = curp*curp;

        if(base<L)
        {
            base = ((L+curp-1)/curp)*curp;
        }

        for(ll j=base; j<=R; j+=curp)
        {
            isprm[j-L]=false;
        }
    }

    for(ll i=0; i<=R-L; i++)
    {
        if(isprm[i]==true){
            cout<<L+i<<" ";
        }
    }
    cout<<endl;


}
int main()
{
    int L = 29;
    int R = 700;
    sieve(M);
    segmented_sieve(L,R);

    return 0;
}

```
### SOURCE:
[ProgrammingPata](https://medium.com/%E0%A6%AA%E0%A7%8D%E0%A6%B0%E0%A7%8B%E0%A6%97%E0%A7%8D%E0%A6%B0%E0%A6%BE%E0%A6%AE%E0%A6%BF%E0%A6%82-%E0%A6%AA%E0%A6%BE%E0%A6%A4%E0%A6%BE/segmented-sieve-number-theory-1af0602dba39)  

