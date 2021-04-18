package atlc.java;

/**
 * 1.创建一个实现Runnable接口的类
 * 2.实现类去实现Runable中的抽象方法：run()
 * 3.创建实现类的对象
 * 4。将此对象作为参数传递到Thread类的构造器中，创建THread的对象
 * 5，通过Thread类的对象调用start()
 *
 *
 *
 * 比较创建线程的两种方式
 * 开发中我们优先选择是实现Runable接口的方式
 * 原因：实现的方式没有类的单继承性的限制
 *      实现的方式可以用于数据共享
 *      两种方式都需要重写Run方法
 */
class  Mthread implements  Runnable{
    @Override
    public void run() {
        for (int i = 0; i < 100; i++) {
            if(i%2==0)
                System.out.println(i);
        }
    }
}

public class ThreadTest1 {


    public static void main(String[] args) {
        Mthread t = new Mthread();
        Thread a = new Thread(t);
        a.start();
    }
}