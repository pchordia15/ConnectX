[![Build Status](https://travis-ci.org/pchordia15/ConnectX.svg?branch=master)](https://travis-ci.org/pchordia15/ConnectX)

* Priyanka Chordia

Bugs Found:

The bug is caused due to inBounds(int w, int h) function.

1. TEST(ConnectXTest, inBoundsWidth)
** Bug Description:** The bug occurs in the test for checking the inBound value of Width. When a negative value of width is passed to the at() function, the output that is expected is INVALID. But the output that we get shows this condition is valid, as it checks the value of width first and it gets inside = FALSE. Next it checks the value of height and as it is positive the value of inside changes to inside = TRUE. Thus returning the entire value of the function as TRUE that shows that it is a valid output. Hence the condition should be checked properly to obtain the correct output and handle the case of negative Width passed with positive Height.

2. TEST(ConnectXTest, outBoundsWidth)
** Bug Description:** The bug occurs in the test for checking the outBound value of Width. When a larger value of width which is not in the range is passed to the at() function, the output that is expected is INVALID. But the output that we get shows this condition is valid, as it checks the value of width first and it gets inside = FALSE. Next it checks the value of height and as it is in the defined range the value of inside changes to inside = TRUE. Thus returning the entire value of the function as TRUE that shows that it is a valid output. Hence the condition should be checked properly to obtain the correct output and handle the case of larger value of Width which is out of the range passed with the value of Height which is in the defined range.
