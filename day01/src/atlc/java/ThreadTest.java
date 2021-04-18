package atlc.java;
/*
1:多线程的创建方式一：继承于thread类
①：创建一个Thread的子类
②：重写Thread类的run()-->将此线程执行的操作声明在run()中
③.创建Thread类的子类的对象;
④：通过此对象调用start(); 启动当前线程  调用当前run()方法
2:两个问题：
①我们不能通过直接调用run（）方法调用线程
②再启动一个线程，遍历1-100的偶数--》不可以让已经strat()的线程去执行，会报错。
我们需要重新创建线程的对象，然后start();
 */
//sample：遍历1到100所有的偶数
class MyThread extends Thread {
    public MyThread() {
        super();
    }

    @Override
    public void run() {

        for(int i=1;i<=100;i++){
            if(i%2==0)
                System.out.println(i);
        }
    }
}

public class ThreadTest{
    public static void main(String[] args) {
        //创建子类的对象
        MyThread t1 = new MyThread();
        //通过此对象调用start方法
        t1.start();
        System.out.println("hello");
    }
}
