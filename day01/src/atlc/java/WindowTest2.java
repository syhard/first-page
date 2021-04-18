package atlc.java;

class Window extends Thread {
    private static int ticket = 100;
    private static Object obj=new Object();
    Window(String  p){
    super(p);
    }
    Window(){

    }

    public void run() {
        while (true) {
        synchronized (obj){
            if (ticket > 0){
                System.out.println(getName() + ":卖票，票号为:" + ticket--);
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            else
                break;
        }
        }
    }
}
public class WindowTest2{
    public static void main(String[] args) {
        Window t1 = new Window("窗口1");
       // t1.setName("窗口1");
        Window t2 = new Window();
        t2.setName("窗口2");
        Window t3 = new Window();
        t3.setName("窗口3");
        t1.start();
        t2.start();
        t3.start();
    }
}
