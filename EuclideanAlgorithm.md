# Basic Euclidean Algorithm for GCD: 

The algorithm is based on the below facts.  
•	If we subtract a smaller number from a larger one (we reduce a larger number), GCD doesn’t change. So, if we keep subtracting repeatedly the larger of two, we end up with GCD.  
•	Now instead of subtraction, if we divide the smaller number, the algorithm stops when we find the remainder 0.  

Example:
Gcd (10,35) = 5  
Gcd (10, 25) = 5  
Gcd (10, 15) = 5  
Gcd (10, 5) = 5  
Gcd (5, 5) = 5  

** To reduce the first 3 steps, instead of substruction, we are doing modulo of these two numbers.  
Gcd (10, 35) = 5  
Gcd (10, 35%10) = 5;  
Gcd (10, 5) = 5;  

Now, 10%5 = 0;  
So, the answer is 5 ... 

#### CODE:

```c++
#include<bits/stdc++.h>
using namespace std;

int euclidean(int a, int b)
{
    if(a==0)
        return b;

    return euclidean(b%a,a);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a,b;
        cin>>a>>b;

        int gcd = euclidean(a,b);

        cout<<gcd<<endl;
    }

    return 0;
}

```

#### SOURCE
[GreeksForGreeks](https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/)


# Extended Euclidean Algorithm:

GCD(a,b) has the property that:  ax + by = gcd(a,b)  

Now we have to find the value of x and y...

<pre> 
ax + by = gcd(a,b)  
        = gcd(b,a%b)  
        = bx<sub>1</sub> + (a%b)y<sub>1</sub>  
        = bx<sub>1</sub> + { a - (a/b)*b }y<sub>1</sub>  
        = bx<sub>1</sub> + ay<sub>1</sub> - (a/b)*by<sub>1</sub>   
        = ay<sub>1</sub> + bx<sub>1</sub> - b(a/b)y<sub>1</sub>  
        = ay<sub>1</sub> + b{ x<sub>1</sub> - (a/b)y<sub>1</sub> }
        </pre> 
        
From the above equation we get:
<pre>   ax + by = ay<sub>1</sub> + b{ x<sub>1</sub> - (a/b)y<sub>1</sub> } </pre>  

Comparing the Coefficients of a and b, we get 
<pre>     x = y<sub>1</sub>
     y = x<sub>1</sub> - (a/b)y<sub>1</sub></pre>
     
#### CODE:
```c++
#include<bits/stdc++.h>

using namespace std;

struct xyg{
    int x;
    int y;
    int g;
};

xyg exteuclid(int a, int b)
{
    xyg ans;
    if(b==0)
    {
        ans.x=1;
        ans.y=0;
        ans.g=a;

        return ans;
    }

    xyg sm = exteuclid(b,a%b);
    ans.x = sm.y;
    ans.y = sm.x - ((a/b)*sm.y);
    ans.g = sm.g;

    return ans;
}

int main()
{

    int a,b;
    cin>>a>>b;

    xyg p = exteuclid(a,b);
    cout<<p.x<<" "<<p.y<<" "<<p.g<<endl;


    return 0;
}

```

#### SOURCE:
[GreeksForGreeks](https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/)  
[ApnaCollege](https://www.youtube.com/watch?v=0oP6XLTI2tY)  

