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

```
### SOURCE:

# Segmented Sieve
### CODE:
```c++

```
### SOURCE:


