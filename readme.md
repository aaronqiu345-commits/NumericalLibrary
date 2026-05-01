## A Small Numerical Library
--------------------------
How to run:
1: Open a terminal in the project folder.
2: Send command: "make" or "make all" (without the quotes)
3: Send command: "./math \[argument]
Replace \[argument] with any of the following:
-s -c -t -e -a
In order, sine, cosine, tangent, exponential, or all at once.


Notes
-----------
While running sine or cosine, you may notice a deviation from the actual math function as the number passed in becomes larger.
This is because sine/cosine waves wrap around their values, while the Pade approximant formulas use exponentials to mimic a sine/cosine wave.
For example, π/2 and 13π/2 are treated the same on a real sine wave. However, the Pade approximant is centered around 0, and the exponentials in its expression cause it to decrease in accuracy rapidly as X increases or decreases past 2π.