
#include<bits/stdc++.h>

using namespace std;

void heapify(int ar[], int n, int i)
{
    int m = i;
    int b = 2*i+1;
    int d = 2*i+2;

    if(b<n && ar[m]<ar[b])
    {
        m = b;
    }
    if(d<n && ar[m]<ar[d])
    {
        m = d;
    }

    if(m!=i)
    {
        swap(ar[i],ar[m]);
        heapify(ar,n,m);
    }
}

void Heap_sort(int ar[], int n)
{
    int i, mh[n+1];
    cout<<"After creating max heap..."<<endl;

    //creating max heap... I tried this step...
    for(i=0; i<n; i++)
    {
        mh[i+1] = ar[i];
        int k = i+1;
        while(k>0){
            if(mh[k/2]<mh[k]){
                swap(mh[k/2],mh[k]);
            }
            k/=2;
        }
    }

    for(i = 1 ; i<=n; i++)
    {
        ar[i-1] = mh[i];
        cout<<ar[i-1]<<" ";

    }
    cout<<endl;

    for(i=n-1; i>=0; i--)
    {
        swap(ar[0],ar[i]);
        heapify(ar,i,0);
    }
}

int main()
{
    int ar[] = { 25, 35, 15, 20, 10, 60, 55};
    int n = sizeof(ar)/sizeof(ar[0]);

    cout<<"Before implementation..."<<endl;
    for(int i = 0 ; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    Heap_sort(ar,n);

    cout<<"Sorted Array..."<<endl;
    for(int i = 0 ; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    return 0;
}
