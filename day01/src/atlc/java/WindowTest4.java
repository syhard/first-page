package atlc.java;
/**
 * 使用同步方法处理继承Thread类的方式中的线程安全
 */
class Window4 extends Thread {
    private static int ticket = 100;
    private static Object obj=new Object();
    Window4(String  p){
        super(p);
    }
    Window4(){

    }

    public void run() {
        while (true) {
            show();
        }
    }
    private static synchronized void show(){
            if (ticket > 0){
                System.out.println(Thread.currentThread().getName() + ":卖票，票号为:" + ticket--);
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

        }
    }


public class WindowTest4{
    public static void main(String[] args) {
        Window4 t1 = new Window4("窗口1");
        // t1.setName("窗口1");
        Window4 t2 = new Window4();
        t2.setName("窗口2");
        Window4 t3 = new Window4();
        t3.setName("窗口3");
        t1.start();
        t2.start();
        t3.start();
    }
}
