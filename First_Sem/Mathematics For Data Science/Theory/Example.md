Proof: (f∘g)(x)(f∘g)(x) is Linear if f(x)f(x) and g(x)g(x) are Linear

Let ff and gg be linear functions. A function h(x)h(x) is linear if it can be written in the form:
h(x)=ax+b
h(x)=ax+b

where a,ba,b are constants and a≠0a=0.
Step 1: Define f(x)f(x) and g(x)g(x) as Linear Functions

Let:
g(x)=m1x+c1
g(x)=m1​x+c1​
f(x)=m2x+c2
f(x)=m2​x+c2​

where m1,m2m1​,m2​ are slopes and c1,c2c1​,c2​ are intercepts.
Step 2: Compute (f∘g)(x)(f∘g)(x)

By definition, function composition means:
(f∘g)(x)=f(g(x))
(f∘g)(x)=f(g(x))

Substituting g(x)g(x):
(f∘g)(x)=f(m1x+c1)
(f∘g)(x)=f(m1​x+c1​)

Now, using the definition of f(x)f(x):
f(m1x+c1)=m2(m1x+c1)+c2
f(m1​x+c1​)=m2​(m1​x+c1​)+c2​

Expanding:
(f∘g)(x)=(m2m1)x+(m2c1+c2)
(f∘g)(x)=(m2​m1​)x+(m2​c1​+c2​)
Step 3: Verify Linearity

The resulting function is:
(f∘g)(x)=m3x+c3
(f∘g)(x)=m3​x+c3​

where m3=m2m1m3​=m2​m1​ and c3=m2c1+c2c3​=m2​c1​+c2​. Since this function is still of the form ax+bax+b, it is linear.

Thus, the composition of two linear functions is also a linear function.
Illustration with Examples
Example 1: Simple Case

Let:
g(x)=2x+3
g(x)=2x+3
f(x)=4x+5
f(x)=4x+5

Compute (f∘g)(x)(f∘g)(x):
(f∘g)(x)=f(2x+3)
(f∘g)(x)=f(2x+3)
=4(2x+3)+5
=4(2x+3)+5
=8x+12+5
=8x+12+5
=8x+17
=8x+17

which is still linear.
Example 2: Identity Function

If g(x)=xg(x)=x and f(x)=3x+2f(x)=3x+2:
(f∘g)(x)=f(x)=3x+2
(f∘g)(x)=f(x)=3x+2

which is still linear.
Example 3: Scaling and Shifting

Let g(x)=−x+4g(x)=−x+4 and f(x)=5x−1f(x)=5x−1:
(f∘g)(x)=f(−x+4)
(f∘g)(x)=f(−x+4)
=5(−x+4)−1
=5(−x+4)−1
=−5x+20−1
=−5x+20−1
=−5x+19
=−5x+19

which is again linear.
Conclusion

Since the composition of two linear functions always results in another linear function, we have proved that f∘gf∘g is linear if ff and gg are linear.