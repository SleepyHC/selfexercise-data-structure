## *Overall Description*

我们可以把递归理解为对于自身的调用

也就是说

​	**将第一个大任务拆分成有一定重复的小任务**

用一个**例子**解释一下

如何求X^n？

是不是会有很多次重复的乘法

1__我们可以用简单的for循环

2__我们可以认为是X^(n/2)*X^(n/2)

​		那么从这个角度 为了求X^(n/2)--其实调用了原来求X^n的函数

​				hint 这时也要去讨论n是否为偶数

这时候，应该明白什么是递归了

介绍递归的两种基本形式吧



我们换一个例子

求从一加到n的和

\`#include <stdio.h>`



`int addition(int n)`

`{`

  `if(n==1)`

​    `return 1;`

  `else`

​    `return n + addition(n - 1);`

`}`



`int main()`

`{`

  `int n = 100;`

  `printf("%d\n", addition(n));`

`}`(具体代码参见example1-addition.cpp)





在addition函数中我们再次调用了addition函数

而如果还有其它操作时我们有两种位置放这些操作

**一个是在内部调用函数之前，一种是在内部调用函数之后**

这两种的效果是不一样的

如果在调用函数之前是先执行操作再调用函数，**从外面打开套娃**

如果在调用函数之后实现调用函数，而函数里面也有相同的操作：所以是先执行里面的操作，**从里面打开套娃**