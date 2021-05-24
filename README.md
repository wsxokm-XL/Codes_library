# Codes_library
my codes

[toc]

## c++

### 1. 计算日期：

输入三个正整数month、day、year分别表示月、日、年。首先检验输入是否表示一个合法的日期，如果是合法日期则计算dayNum表示此日期为该年的第几天，否则输出"Illegal"。

方法：`if` `switch`

代码文件：date.cpp



### 2. 欧几里得算法：

输入两个整数m，n，输出它们的最大公约数（gcd）。

思想：gcd(m,n)=gcd(m,n%m) ; gcd(m,0)=m

 1. 非递归：

    代码文件：gcd_unrecursion.cpp

	2. 递归：

    代码文件：gcd_recursion.cpp

    

### 3. 爬楼梯（非递归实现）：

要走上一个有n级台阶的楼梯，你可以一次走一级，也可以一次走两级。计算有多少种走法。

代码文件：gcd_unrecursion.cpp



### 4. 开灯问题：

有 1000盏灯，编号为 1~ n ~ 1000。一共有k个人，第n个人按下编号为n的倍数的灯的开关，输出开着的灯的编号。

代码文件：lights.cpp



### 5. 进制转换

输入两个十进制正整数 n 和 base(2≤base≤16)，将 n 转换为 base 进制后输出。

代码文件：bash_conversion.cpp



### 6.冰雹猜想

给出一个正整数 n(*n*≤100)，然后对这个数字一直进行下面的操作：如果这个数字是奇数，那么将其乘 3 再加 1，否则除以 2。经过若干次循环后，最终都会回到 1。根据给定的数字 n，验证这个猜想，即输出整个变化序列。

代码文件：hail_conjecture.cpp



## c

### 1. 生成随机DNA序列：

 1. 生成长度为n的随机DNA序列

    代码文件：generate_DNA.c

    

 2. 生成指定GC含量的长度为n的随机DNA序列

    代码文件：generate_GCper_DNA.c

    reference：https://blog.csdn.net/qq_43655831/article/details/108245306?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-0&spm=1001.2101.3001.4242



### 2. 字符串的匹配算法（基于DNA序列）：

有一个字符串$S$和一个模式字符串$P$，查找$P$在$S$中的位置。

 1. 暴力匹配算法（BF）：

    思想：

    假设当前字符串$S$匹配到了$i$位置，模式串$P$匹配到$j$位置，分为两种情况：

    - 如果当前字符匹配成功，也就是`S[i]=P[j]​`，则`i++, j++`，继续匹配下一个字符。
    - 如果匹配失败，也就是`S[i]!=P[j]`，则`i-=(j-1), j=0`。也就是将`i`回溯，`j`置零。

    代码文件：BF.c

    

 2. KMP算法：

    思想：空间换时间，利用next数组储存模式字符串P的信息。

    代码文件：KMP.c

    reference：https://blog.csdn.net/dark_cy/article/details/88698736

    

### 3. 排序



### 4.DNA序列全局比对：

随机生成2个长度为100，GC含量为41%的随机DNA序列，根据打分规则输出最优的成对全局比对。

Needleman-Wunsch算法

代码文件：opitmal_alignment.c



## shell 





## 算法优化

### 1. 快速幂算法：

reference：https://blog.csdn.net/qq_19782019/article/details/85621386

