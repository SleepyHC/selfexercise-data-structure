/**回顾kmp算法
 * 首先就是求出next值
 * 然后开始匹配
 * 假设主串指针为i
 *     子串指针为j--(ij其实全部都是int)
 * 当匹配到某一时候，i，j所对应的值不相等时
 * kmp的优势就出来了
 * --i不变--j的数值变为next[j]
 * 其实最后节省的步骤就是i的不变和j回溯的长度减少
 * 
 * ………………注意，在这里主串和子串是从0号位开始储存的，而对于next数组中next[0]=-1
 * 
 * */

/**而next数组怎么求
 * 事实上，因为核心是要将 **j的数值变为next[j]**  next[j]事实上就是子串中第j位前面最大相同子串长度
 * 
 * 
 * 初始化
 *      子串为b[]
 *      前缀指针为k
 *      后缀指针为h
 * 
 * 需要考虑几个步骤
 * 
 * --b[k]==b[h] 
 * --b[k]!=b[h]
 * --如何赋值next数组
 * */

# include"string.cpp"

void getNext(SqString t,int next[])
{
    int k=-1, h=0;//初始化指针
    next[h] = -1;
    while(k<t.length)
    {
        if(k==-1||t.data[k]==t.data[h])
        {
            k++;
            h++;
            next[h] = k;//因为数组中从0开始，所以为了得到正确的个数，要先自增
        }
        else
            k = next[k];//原理其实和kmp的主函数配对原理一样，就是t[k-1]匹配已经成功过了，所以要看前面有没有相等的最大字符串，这样可以节约时间
    }
}