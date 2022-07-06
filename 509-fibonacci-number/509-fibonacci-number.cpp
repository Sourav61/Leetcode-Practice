class Solution {
public:
    int fibo(int a,int b,int n){
        while(n){
            cout<<a<<" "<<b<<endl;
            int temp = b;
            b = a + b;
            a = temp;
            n--;
        }
        
        return b;
    }
    
    int fib(int n) {
        
        int a = 0;
        int b = 1;
        
        if(n==0){
            return a;
        }
        
        return fibo(a,b,n-1);
    }
};