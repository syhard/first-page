package atlc.exer;
//练习：创建两个分线程，一个线程遍历
class Jthread extends Thread{
    @Override
    public void run() {
        for(int i=1;i<=100;i++){
            if(i%2!=0)
            System.out.println(i);
        }
    }
}

class Othread extends Thread{
    @Override
    public void run() {
        for(int i=0;i<=100;i++){
            if(i%2==0)
                System.out.println(i);
        }
    }
}

public class ThreadDemo {
    public static void main(String[] args) {
        Jthread t1 = new Jthread();
        Othread t2 = new Othread();
        t1.start();
        t2.start();
    }
}
