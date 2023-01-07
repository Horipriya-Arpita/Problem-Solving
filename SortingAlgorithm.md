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

```

### SOURCE:
[ApnaCollege](https://www.youtube.com/watch?v=4z9I6ZmeLOQ) 

# Quick Sort 
### CODE:
```c++

```
### SOURCE:
[ApnaCollege](https://www.youtube.com/watch?v=Dl6HT-NM_q4&t=713s)

# Heap Sort 
