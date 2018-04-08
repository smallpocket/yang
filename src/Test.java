/**
 * @Author_ heper
 * @Time_ 2018/4/3 8:15
 * @Version_ 1.0
 * @Title_ java方法是按值调用还是按引用
 */

/**
 * Java 语言的参数传递只有按值传递。
 * 当一个实例对象作为参数被传递到方法中时，参数的值就是该对象的引用的一个副本。
 * 指向同一个对象，对象的内容可以在被调用的方法内改变，
 * 但对象的引用(不是引用的副本) 是永远不会改变的。
 * 按值传递传递了存储单元的内容,而不是存储单元的引用
 * 对象是因为他的内容就是存储单元的引用
 * 类似传递一个指针,指针是新的,但是都指向一块内存地址
 * Java的参数传递，不管是基本数据类型还是引用类型的参数，都是按值传递，没有按引用传递！
 */
public class Test {
    static void change(Atest atest)
    {
        atest.c='y';
    }
    public static void main(String[] args)
    {
        Atest anew =new Atest();
        anew.c='x';
        System.out.println(anew.c);
        change(anew);
        System.out.println(anew.c);
    }
}
