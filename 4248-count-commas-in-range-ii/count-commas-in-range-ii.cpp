class Solution {
public:
    
    #define ll long long
    
    long long countCommas(long long n) {
        if(n<1000){
            return 0;
        }
        ll cnt =0;
        ll last=1000;
        while(n>=last){
            cnt+=(n-last+1);
            last*=1000;
        }
        return cnt;
    }
};