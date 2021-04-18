package atlc.java;

public class ThreadMethodTest {
    /**
     *测试Thread中的常用方法
     * 1.start() 启动当前线程，调用此线程中的run()方法
     * 2.run() 将创建线程执行的操作重写入此方法
     * 3.：String getName（）;返回当前代码线程的名称
     * 4.void setName(String name);设置该线程名字
     * 5.static Thraed currentThread():返回当前线程。在Thrad子类中就是this,通常用于主线程和Runable实现类
     * 6.yield（）;   释放当前cpu的执行权
     * 7：join();在线程A中调用调用线程b的join()方法，线程a进入阻塞状态，知道线程b执行完成以后，状态消失：
     * 8:sleep(long millitimie):让当前线程指定多少毫秒
     * 9：isAlive():判断当前线程是否被执行。
     * 线程的优先级
     * 1.
     * MAX_PRIORITY: 10
     * MIN_PRIORITY: 1
     * NORM_PRIORITY: 5
     * 2.如何获取和设置当前线程的优先级：
     * 1:getpriority() 获取当前线程的优先级
     * 2:serpriority(int i) 设置当前线程的优先级
     */
}
