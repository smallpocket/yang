package interfaceTest;

/**
 * @Author_ heper
 * @Time_ 2018/3/31 8:44
 * @Version_
 * @Title_借口默认方法
 */
public interface DefaultMethod {
    //借口方法默认实现
    //默认方法不需要在实现接口的类中进行实现,当然如果实现了的话就可以覆盖默认方法
    //如果想在接口中新增一个方法,默认方法可以避免已经实现了这个接口的类无法编译
    default void MouseClicked(int x )
    {

    }
}
