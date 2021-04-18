package atlc.java;
/**
 * sample:创建三个窗口卖票，总票数100张，实现Runable接口的方式
 * 1：问题：卖票的过程中出现了重票，错票--》出现的线程的安全问题
 * 2.问题出现的原因：当某个线程操作车票的过程中，尚未操作完成时，其他线程操作起来，也操作车票。
 * 3.如何解决：当一个线程a的操作ticket的时候，其他线程不能参与进来，知道线程操作完ticket时，线程才可以操作ticket
 * 这种情况下即使线程a出现了阻塞，也不能改变。
 * 4.在java中，我们通过同步机制，来解决线程的安全问题.
 * 方式一：同步代码块
 * synchronized(同步监视器){
 *     //需要被同步的代码
 * }
 * 说明：1.操作共享数据的代码，即为需要被同步的代码
 *      2.共享数据：多个线程共同操作的变量,比如：ticket就是共享数据
 *      3.同步监视器：俗称锁。任何一个类的对象都可以充当锁。
 *      要求：多个线程必须共用一把锁
 * 方法二：同步方法
 *  如果操作共享数据的代码完整的声明在一个方法中，我们不妨将此方法声明为同步到的
 * 操作同步代码时，只能有一个线程参与，其他线程等待。
 */

import static java.lang.Thread.currentThread;
import static java.lang.Thread.sleep;

class Widouw1 implements Runnable{
    private int ticket =100;
    Object obj=new Object();
    @Override
    public void run() {

        while (true) {
            synchronized (obj) {
                if (ticket > 0) {
                    try {
                        sleep(100);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    System.out.println(currentThread().getName() + ":卖票，票号为" + ticket);
                    ticket--;
                }
            }
        }
    }
}
public class WindowTest1 {
    public static void main(String[] args) {
        Widouw1 a = new  Widouw1();
        Thread t1 = new Thread(a);
        t1.setName("窗口一");
        Thread t2= new Thread(a);
        t2.setName("窗口二");
        Thread t3 = new Thread(a);
        t3.setName("窗口三");
        t1.start();
        t2.start();
        t3.start();
    }
}
