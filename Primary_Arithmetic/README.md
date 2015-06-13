Primary Arithmetic
--------------

*Problem UVA ID 10189: MineSweeper*
*Resolved in C by GOMA.*
*2013-12-26*


The Folder "Case_Tests" contains 2 case tests to the problem.


The Problem
----------------------------------------------------------
Children are taught to add multi-digit numbers from right-to-left onedigit at a time. Many find the "carry" operation - in which a 1 is carried from one digit position to be added to the next - to be a significant challenge. Your job is to count the number of carry operations for each of a set of addition problems so that educators may asses their difficulty

The Input
------------------
Each line of input contains two unsigned integers less than 10 digits. The last line of input contains '0 0'.

The Output
---------------
For each line of input except the last you should compute and print the number of carry operations that would result from adding the two numbers, in the format shown bellow

Sample Input
---
<pre>
123 456
555 555
123 594
0 0
</pre>

Sample Output
--
<pre>
No carry operation.
3 carry operations.
1 carry operation.
</pre>
