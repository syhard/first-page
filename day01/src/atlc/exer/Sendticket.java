package atlc.exer;

import static java.lang.Thread.*;

class Widouw1 implements Runnable{
    private int ticket =100;
    @Override
    public void run() {
        while (true) {
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
public class Sendticket {
    public static void main(String[] args) {
        Widouw1 a = new Widouw1();
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
