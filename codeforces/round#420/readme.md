# Codeforces Round #420

## A. Okabe and Future Gadget Laboratory
给一个数组，问数组里面除了1以外的数是否都可以用同行和同列各一个数相加得到

### 解法
暴力遍历即可，简单题

## B. Okabe and Banana Trees
给一个方程，y = -x/m + b; 在该斜线与x, y轴的三角区域内选择一个矩形，使得矩形里的每个点(x,y), 
x1+y1 + x2+y2 + x3+y3 + ... + xn+yn最大，输出最大值。

### 解法
由题可知，矩形一定包含了原点(0,0),因为如果不包含的话，完全可以使矩形扩展到包含原点而使得值更大。
设右上角的点为(x,y),那么结果为：(x+1)*(y+1)*(x+y)/2, 而x = m(b-y), 枚举0<=y<=b，得到x,
然后取最大值即可.


## C. Okabe and Boxes
有n个数字，给2n个操作，操作有两种，分别为：
1. add(x),忘栈里增加数字x, 
2. remove, 从栈里取出当前最小的数字。
而被操作者可以对栈里的数字任何时刻进行排序，问一共需要排序几次，使得最后取出的值为1.2.3....n.

### 解法
维护一个当前为排序的栈即可，每次remove判断当前栈顶是否为要求的数字，如果不是则排序，是则取出。