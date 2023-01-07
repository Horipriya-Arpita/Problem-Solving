#include<bits/stdc++.h>

using namespace std;

void counting_sort(int ar[], int n)
{
    int i, mx = ar[0];
    for(i=0; i<n; i++)
    {
        mx = max(ar[i],mx);
    }

    int cnt[mx+1];
    int out[n];

    memset(cnt,0,sizeof(cnt));

    for(i=0; i<n; i++)
    {
        cnt[ar[i]]++;
    }

    for(i=1; i<n; i++)
    {
        cnt[i]+=cnt[i-1];
    }

    for(i=n-1; i>=0; i--)
    {
        out[--cnt[ar[i]]] = ar[i];
    }

    for(i=0; i<n; i++)
    {
        ar[i] = out[i];
    }

}

int main()
{
    int ar[] = {2,6,1,2,1,5,4,5,3};
    int n = sizeof(ar)/sizeof(ar[0]);

    counting_sort(ar,n);

    for(int i = 0; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    return 0;
}
