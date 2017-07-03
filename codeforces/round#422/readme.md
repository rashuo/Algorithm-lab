# Codeforces Round #420

## A. I'm bored with life
求GCD(x!,y!), min(x,y)<=12;

### 解法
最小的那个的阶乘即是答案

## B. Crossword solving
给两个字符串s1和s2, 问s1最少改变多少个字符能成为s2的子串。

### 解法
数据不大，暴力求解即可

## C. Hacker, pack your bags!
给出n和x, (2<=n,x<=2e5), 有n对l[i],r[i],cost[i], 代表从第l[i]天到l[j]天有一个
旅行，花费为cost[i], 问：从这n对找两个不相交的旅行使得它们的天数和刚好为x的最小花费。

### 解法
把r+1,然后把坐标点离散话排序，遇到l就计算要这个旅行的最小花费，遇到r就更新备选库.

## D. My pretty girl Noora
求t^0*f[1]+t^1*f[2]+...+t^(r-l)*f[r], 其实就是求f[i],
其中f[n] = n个女孩参加比赛两两比较，可以每次分成任意组（每组数量相同），然后每组
选出一个，进行下一轮，问最少需要比较多少次。演算后易得，每次分的组数越多，比较的总次数
越少，于是f[i] = f[j]*(i/j)+f[i/j], 其中j为i的最小的除去1和本身的约数，然后用晒素数
的方法求的每个i对应的j，如果i对应的j为本身的话，那么把所有女生分成一组即可.
