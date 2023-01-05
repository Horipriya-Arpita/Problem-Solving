# Chinese Remainder Theorem 

## Formal Definition :  
<pre>Given two sequences of numbers A=[a1,a2,…,an] and M=[m1,m2,…,mn],  
find the smallest solution to the following linear congruence equations,  
if it exists:

           x≡a1(mod m1)  
           x≡a2(mod m2)
             ... 
           x≡an(mod mn)</pre>
           
         
# Weak Form :    
 The weak Chinese Remainder Theorem states the following:

Given two sequences of numbers __A=[a1,a2,…,an]__ and __M=[m1,m2,…,mn],__ where all elements of __M__ are pairwise coprime, there always exists an unique solution to __x__ mod __L__, where __L=m1×m2×⋯×mn__, such that __x__ satisfies the following linear congruence equations:

<pre>x≡a1(mod m1)  
x≡a2(mod m2)  
  ...  
x≡an(mod mn)</pre>
So the weak form of Chinese Remainder Theorem has a constraint: members of the array M must be pairwise coprime.This means that GCD(mi,mj)=1 when i≠j.  

As long as this condition is satisfied, the weak form of CRT state that a solution to x always exists which is “unique mod L”

## Finding a solution 
### When there are just two equations
Let us first just consider two equation: x≡a1(mod m1) and x≡a2(mod m2). What we are going to do is merge these two equations into one equation. Here is how it works.

Since gcd(m1,m2)=1, from Bezout’s Identity, we know that there exists a solution to the following equation:

<pre>    m1p+m2q=1..........................(1) </pre>
Using Extended Euclidean Algorithm, we can find the value of p and q. If we know the value of p and q, then we can say that:
<pre>   x=a1m2q+a2m1p (mod m1m2)tag2 </pre>

See below to understand why so.
<pre>x=a1m2q+a2m1p
x=a1(1–m1p)+a2m1p (Using (1))
x=a1–a1m1p+a2m1p
x=a1+(a2–a1)m1p
∴x≡a1(mod m1)
Similarly, x=a1m2q+a2m1p≡a2(mod m2) </pre>
Great! We now have a possible solution for x, but why did we mod the solution with m1m2? The solution we found may or may not be the smallest.  

#### Proof of Uniquness 
Since there could be infinite solutions, let x1 and x2 be two such solution. Hence we can say the following:

<pre>x1≡a1(mod m1)
x2≡a1(mod m1)
∴x1≡x2(mod m1)
x1–x2≡0(mod m1)
∴m1|x1–x2
Similarly, we can show that m2|x1–x2.</pre>

What can we do with all these information? The difference of any two solutions x1 and x2 is divisible by both m1 and m2. We also know that, m1 and m2 are coprime. Doesn’t that mean, the difference is also divisible by m1×m2? Yes. That’s exactly what we are going towards

<pre>m1m2|x1–x2
x1–x2≡0(mod m1m2)
x1≡x2(mod m1m2)</pre>
The next question I will ask is: if the difference between any two solutions, x1 and x2, is divisible by m1m2, then how many solution can there exist in the range 0 to m1m2–1? Only one. And hence, the solution x is unique to modulo m1m2.

Therefore we can say that the solution x≡a1m2q+a2m1p (mod m1m2) is unique and smallest. Hence, the two equation, x≡a1(mod m1) and x≡a2(mod m2), after merging becomes x≡a1m2q+a2m1p (mod m1m2)

### When there are n equations
Since we know how to merge two equations into one, all we need to do is take the first two equations from n equations and merge them. Then we are left with n−1 equations. Since all the elements of M were pairwise coprime, the new modulus is also coprime. Hence, we can continue to merge the equations until there is only one equation left. The equation left is our answer.

#### CODE:
For Two Equations: 
```c++
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

int crt_weak(int a1, int a2, int m1, int m2)
{
    xyg pq = ext_euclid(m1,m2);
    int p = pq.x;
    int q = pq.y;

    int x = (a1*m2*q + a2*m1*p) % (m1*m2);

    return x;
}

int main()
{
    int a1,a2,m1,m2;
    cin>>a1>>a2>>m1>>m2;

    int x = crt_weak(a1,a2,m1,m2);

    cout<<x<<endl;

    return 0;
}

```
For Many Equations:
```c++
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
```

#### SOURCE:
[forthright48](https://forthright48.com/chinese-remainder-theorem-part-1-coprime-moduli/)

# Strong Form
Given two sequences of numbers A=[a1,a2,…,an] and M=[m1,m2,…,mn], find the smallest solution to the following linear congruence equations if it exists:
<pre>x≡a1(mod m1)
x≡a2(mod m2)
  ...
x≡an(mod mn)</pre>
__Note:__ The elements of M are not pairwise coprime

### Working With Two Equations
Before we go on to deal with n equations, let us first see how to deal with two equations. Just like before, we will try to merge two equations into one.

So given the two equation x≡a1(mod m1) and x≡a2(mod m2), find the smallest solution to x if it exists.

#### Existance of Solution
Suppose, gcd(m1,m2)=g. In that case, the following constraint must be satisfied: a1≡a2(mod g), otherwise there does not exist any solution to x. Why is that?

<pre>We know that, 
x≡a1(mod m1)
or, x–a1≡0(mod m1)
or, m1|x–a1

Since m1 divides x–a1, any divisor of m1 also divides x–a1, including g.

∴ x–a1≡0(mod g).

Similarly, we can show that, x–a2≡0(mod g) is also true.

∴ x–a1≡x–a2(mod g)
or, a1≡a2(mod g)
or, a1–a2≡(mod g)
or g|(a1–a2)

Therefore, g must divide a1–a2, otherwise, there is conflict and no solution exists. 
From this point, we assume that g|a1–a2.</pre>

#### Finding Solution
Just like last time, we use Bezout’s identity to find a solution to x. From Bezout’s identity, we know that there exists a solution to the following equations:
<pre>    m1p+m2q=g
Since both side is divisible by g, we can rewrite it as:
      m1gp+m2gq=1 </pre>
Using Extended Euclidean Algorithm, we can easily find values of p and q. Simply call the function ext_gcd(m1/g, m2/g, p, q) and it should be calculated automatically.

Once we know the value of p and q, we can claim that the solution to x is the following:
<pre>   x=a1m2gq+a2m1gp</pre>
Why is that? Look below.

<pre>     x=a1m2gq+a2m1gp
From Bezout’s Identity, we know that m1gp=1–m2gq 
So, x=a1m2gq+a2(1–m2gq)
or, x=a2+(a1–a2)m2gq
Since, g|(a1–a2)
x=a2+a1–a2gm2q
∴ x≡a2(mod m2)
Similarly, x≡a1(mod m1)</pre>
Hence, x=a1m1gq+a2m2gp is a valid solution. It may not be the smallest solution though.

#### Finding Smallest Solution
Let x1 and x2 be adjacent two solutions. Then the following are true:
<pre>x1≡a1(mod m1)
x2≡a1(mod m1)
x1≡x2(mod m1)
x1–x2≡0(mod m1)
m1|x1–x2
Similarly, m2|x1–x2 </pre>
Since both m1 and m2 divides x1–x2, we can say that LCM(m1,m2) also divides x1−x2.

Since any two adjacent solution of x is divisible by L=LCM(m1,m2), then there cannot be more than one solution that lies on the range 0 to L−1. Hence, the following is the smallest solution to x:

<pre>   x≡a1m2gq+a2m1gp(mod LCM(m1,m2)) </pre>

#### Working with n Equations
When there are n equations, we simply merge two equations at a time until there is only one left. The last remaining equation is our desired answer. If at any point, if we are unable to merge two equations due to conflict, i.e, ai≢aj (mod GCD(mi,mj)), then there is no solution.

### CODE:
For Two Equations:
```c++
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

int crt_strong(int a1, int a2, int m1, int m2)
{
    int gc = __gcd(m1,m2);

    if(a1%gc != a2%gc){

        return -1;
    }

    cout<<gc<<"gc"<<endl;
    xyg pq = ext_euclid(m1/gc,m2/gc);

    int mod = (m1/gc)*m2;

    int p = pq.x;
    int q = pq.y;

    cout<<p<<" " <<q<<endl;

    int x = (a1*(m2/gc)*q + a2*(m1/gc)*p) % mod;

    x+=mod;
    x+=mod;

    return x;
}

int main()
{
    int a1,a2,m1,m2;
    cin>>a1>>a2>>m1>>m2;

    int x = crt_strong(a1,a2,m1,m2);

    cout<<x<<endl;


    return 0;
}
```
For many equations:
```c++
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

int crt_strong(int a[], int m[])
{
    int a1,a2,m1,m2,x,mod;
    a1 = a[0];
    m1 = m[0];

    for(int i = 1; i < 3; i++)
    {
        a2 = a[i];
        m2 = m[i];

        int g = __gcd(m1,m2);

        if(a1%g != a2%g){
            return -1;
        }

        xyg pq = ext_euclid(m1/g,m2/g);
        int p = pq.x;
        int q = pq.y;

        mod = (m1/g)*m2;

        x = (a1*(m2/g)*q + a2*(m1/g)*p) % mod;

        a1 = x;
        m1 = mod;
    }

    if (x < 0) x += mod; /** Result is not suppose to be negative*/
    return x;
}

int main()
{
    int a[] = {2, 2, 4};
    int m[] = {3, 6, 5};

    int x = crt_strong(a,m);

    cout<<x<<endl;

    return 0;
}

```

### SOURCE:
[forthright48](https://forthright48.com/chinese-remainder-theorem-part-2-non-coprime-moduli/)
