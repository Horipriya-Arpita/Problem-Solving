#include<bits/stdc++.h>

using namespace std;

void Count_sort(int ar[], int n, int ps)
{
    int cnt[10] = {0};
    int i;
    int out[n];
    for(i=0; i<n; i++)
    {
        cnt[(ar[i]/ps)%10]++;
    }

    for(i=1; i<10; i++)
    {
        cnt[i]+=cnt[i-1];
    }

    for(i=n-1; i>=0; i--)
    {
        out[--cnt[(ar[i]/ps)%10]] = ar[i];
    }

    for(i=0; i<n; i++)
    {
        ar[i] = out[i];
    }
}

void Redix_sort(int ar[], int n)
{
    int i;
    int mx=ar[0];
    for(i=0; i<n; i++)
    {
        mx = max(ar[i],mx);
    }

    for(int ps = 1; mx/ps>0; ps*=10)
    {
        Count_sort(ar,n,ps);
    }
}

int main()
{
    int ar[] = {123, 45, 78, 9, 656, 87, 77, 389, 453, 55, 3};
    int n = sizeof(ar)/sizeof(ar[0]);

    Redix_sort(ar,n);

    for(int i = 0; i < n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    return 0;
}
