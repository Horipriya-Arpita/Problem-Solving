# Sorting Algorithm

# Counting Sort
### CODE:
```c++
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

```
### SOURCE:
[ApnaCollege](https://www.youtube.com/watch?v=imqr13aIBAY) 


# Bucket Sort

### CODE: 
```c++
#include<bits/stdc++.h>

using namespace std;

void Bucket_sort(float ar[], int n)
{
    vector<float> b[n];
    int i,j,k=0;

    for(i=0; i<n; i++)
    {
        int bi = n*ar[i];
        b[bi].push_back(ar[i]);
    }

    for(i=0; i<n; i++)
    {
        sort(b[i].begin(), b[i].end());
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<b[i].size(); j++)
        {
            ar[k++]=b[i][j];
        }
    }
}

int main()
{
    float ar[] = {0.42, 0.65, 0.03, 0.49, 0.32, 0.15, 0.45, 0.38, 0.19, 0.78};

    int n = sizeof(ar)/sizeof(ar[0]);

    Bucket_sort(ar,n);

    for(int i = 0; i < n; i++)
    {
        cout<<ar[i]<<"  ";
    }
    cout<<endl;

    return 0;
}

```
### SOURCE:
[GreeksForGreeks](https://www.geeksforgeeks.org/bucket-sort-2/)  
[Programiz](https://www.programiz.com/dsa/bucket-sort)


# Redix Sort

### CODE: 
```c++
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

```
### SOURCE: 
[JennysLectures](https://www.youtube.com/watch?v=Il45xNUHGp0)  


# Merge Sort 
### CODE:
```c++
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

```
### SOURCE:
[ApnaCollege](https://www.youtube.com/watch?v=4z9I6ZmeLOQ) 

# Quick Sort 
### CODE:
```c++
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
```
### SOURCE:
[ApnaCollege](https://www.youtube.com/watch?v=Dl6HT-NM_q4&t=713s)

# Heap Sort 
### CODE:
```c++
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

    //creating max heap...
    for(i=n/2-1; i>=0; i--)
    {
        heapify(ar,n,i);
    }

    for(i = 0 ; i<n; i++)
    {
        cout<<ar[i]<<" ";

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

```
### SOURCE:
[AbdulBari](https://www.youtube.com/watch?v=HqPJF2L5h9U) 
[GreeksForGreeks](https://www.geeksforgeeks.org/heap-sort/)
[JennysLecture](https://www.youtube.com/watch?v=Q_eia3jC9Ts&t=1537s) 

