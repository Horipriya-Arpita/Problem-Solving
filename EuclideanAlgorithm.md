## Basic Euclidean Algorithm for GCD: 

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

#### Code:

