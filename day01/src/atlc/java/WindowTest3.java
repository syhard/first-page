package atlc.java;
/**
 * 使用同步方法来解决线程安全问题
 * 1.同步方法仍然涉及到同步监视器，只是不需要我们显性的声明
 * 2.非静态的同步方法:this
 *   静态的同步方法，同步监视器当前类的本身。
 */

import static java.lang.Thread.currentThread;
import static java.lang.Thread.sleep;

class Widouw2 implements Runnable{
    private int ticket =100;
    @Override
    public void run() {
        while (true) {
            show();
        }
    }
    private synchronized void show(){//同步监视器就是this
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

public class WindowTest3 {
    public static void main(String[] args) {
       Widouw2 a = new Widouw2();
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