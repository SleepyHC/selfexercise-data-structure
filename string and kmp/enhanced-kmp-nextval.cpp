/** 这里的改进版kmp是将next数组中的一种情况排除
 * 当主串匹配到了ac 子串匹配到了abab中的
 * 换一种说法、
 * 
 * 就是子串和主串中的n位匹配，n+1不匹配，此时如果子串指针回退为next[n+1]，
 * 而原来指向的值与回退指向的值相等，就相当于白匹配了一次，
 * 所以改进版就是要规避这个缺点。
 * 
 * 如果这个角度仍然没懂
 * 那我再换一种说法
 * 
 * 什么时候需要用next[k]？
 * --比较的字符不相等的时候
 * 那如果回退之后指向的字符跟回退之前相等的话
 * 是不是就浪费了回退后比较的那一次，因为一定不相等!
 * bingo!
 * 
 * 这种问题看似很小，但是对于一个大子串来说，就可以提升速度
 * 
 * 虽然，时间复杂度都是O(n+m);
 * 
 **/

//建议和“kmp-next.cpp”比较着看//


# include"string.cpp"

void getNextval(SqString t,int next[])
{
    int k=-1, h=0;//初始化指针
    next[h] = -1;
    while(k<t.length)
    {
        if(k==-1||t.data[k]==t.data[h])
        {
            k++;
            h++;

            //重头戏来了，就是这里要比较是否是回退后的字符仍然相等//

            if(t.data[h]==t.data[k])
                next[h] = next[k];
            else
                next[h] = k;//因为数组中从0开始，所以为了得到正确的个数，要先自增
        }
        else
            k = next[k];//原理其实和kmp的主函数配对原理一样，就是t[k-1]匹配已经成功过了，所以要看前面有没有相等的最大字符串，这样可以节约时间
    }
}