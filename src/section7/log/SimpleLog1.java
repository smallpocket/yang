package section7.log;

import java.util.logging.Logger;

/**
 * @Author_ heper
 * @Time_ 2018/4/7 14:12
 * @Version_ 1.0
 * @Title_
 */
public class SimpleLog1
{
    //可以调用 getLogger 方法创建或获取记录器 ：
    //未被引用的日志记录器可能被回收,用一个静态变量存储
    private static final Logger myLogger = Logger.getLogger ( " com . mycompany . myapp " ) ;

    public void test ()
    {
        Logger.getGlobal().info("输出");
    }
}
