package section7.log;

import java.util.logging.Logger;
/**
 * @Author_ heper
 * @Time_ 2018/4/6 20:58
 * @Version_ 1.0
 * @Title_ 日志
 */
public class test
{
    int read ( String file , String pattern )
    {

        Logger . entering ( " com . mycompany . mylib . Reader " , " read " ,
            new Object[]{ file , pattern } ) ;
        Logger . exiting ( " com . mycompany . mylib . Reader " , " read " , count ) ;
        return count ;
    }
}
