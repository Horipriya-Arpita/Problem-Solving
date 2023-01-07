#include<bits/stdc++.h>

using namespace std;

void Merge(int ar[], int m, int l, int r)
{
    int p = m - l + 1;
    int q = r - m;

    int a[p], b[q],i,j,x=l,y=m+1;
    for(i=0; i<p; i++)
    {
        a[i] = ar[x];
        x++;
    }

    for(i=0; i<q; i++)
    {
        b[i] = ar[y];
        y++;
    }
    i=0, j=0;
    int k=l;
    while(i<p && j<q)
    {
        if(a[i]<b[j])
        {
            ar[k] = a[i];
            k++;
            i++;
        }
        else
        {
            ar[k] = b[j];
            k++;
            j++;
        }
    }

    while(i<p)
    {
        ar[k] = a[i];
        k++;
        i++;
    }

    while(j<q)
    {
        ar[k] = b[j];
        k++;
        j++;
    }

}

void Merge_sort(int ar[], int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        Merge_sort(ar,l,m);
        Merge_sort(ar,m+1,r);

        Merge(ar,m,l,r);
    }
}

int main()
{
    int ar[] = {3,6,4,8,9,1,5,6};
    int n = sizeof(ar)/sizeof(ar[0]);

    cout<<"Before Sorting ... "<<endl;

    for(int i =0 ; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    Merge_sort(ar,0,n-1);

    cout<<"After Sorting ... "<<endl;

    for(int i =0 ; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    return 0;
}
