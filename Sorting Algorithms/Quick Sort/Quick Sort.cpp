#include<bits/stdc++.h>

using namespace std;

int partitionn(int ar[], int l, int r)
{
    int piv = ar[r];
    int i=l-1,j;

    for(j=l; j<r; j++)
    {
        if(ar[j]<piv)
        {
            i++;
            swap(ar[i],ar[j]);
        }
    }

    swap(ar[i+1],ar[r]);

    return i+1;
}

void Quick_sort(int ar[], int l, int r)
{
    int m = (l+r)/2;
    swap(ar[m],ar[r]);

    if(l<r)
    {
        int piv = partitionn(ar,l,r);
        Quick_sort(ar,l,piv-1);
        Quick_sort(ar,piv+1,r);
    }

}
int main()
{
    int ar[] = {6,3,9,5,2,8,7};
    int n = sizeof(ar)/sizeof(ar[0]);

    Quick_sort(ar,0,n-1);

    cout<<"After Sorting ... "<<endl;

    for(int i =0 ; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    return 0;
}
