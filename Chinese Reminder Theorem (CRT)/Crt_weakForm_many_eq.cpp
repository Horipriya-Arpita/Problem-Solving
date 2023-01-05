#include<bits/stdc++.h>

using namespace std;

struct xyg{
    int x;
    int y;
    int g;
};

xyg ext_euclid(int a, int b)
{
    xyg ans;
    if(b==0)
    {
        ans.x = 1;
        ans.y = 0;
        ans.g = a;
        return ans;
    }

    xyg sm_ans = ext_euclid(b,a%b);

    ans.x = sm_ans.y;
    ans.y = sm_ans.x - (a/b)*sm_ans.y;
    ans.g = sm_ans.g;

    return ans;
}

int crt_weak(int a[], int m[], int sz)
{
    int a1,a2,m1,m2,x;
    a1 = a[0];
    m1 = m[0];

    for(int i = 1; i < sz; i++)
    {
        a2 = a[i];
        m2 = m[i];

        xyg pq = ext_euclid(m1,m2);
        int p = pq.x;
        int q = pq.y;

        x = (a1*m2*q + a2*m1*p) % (m1*m2);

        a1 = x;
        m1 = m1*m2;
    }

    if (x < 0) x += m1; /** Result is not suppose to be negative*/
    return x;
}

int main()
{
    int a[] = {2, 3, 2};
    int m[] = {3, 5, 7};

    int sz = sizeof(a)/sizeof(a[0]);
    int x = crt_weak(a,m,sz);


    cout<<x<<endl;

    return 0;
}

