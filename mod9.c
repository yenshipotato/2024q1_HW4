#include <stdio.h>
#include <stdint.h>
#define MASK 0x41041041
uint32_t mod9(uint32_t n){
    if(n<9)
        return n;
    n-=9;
    uint32_t tmp=0,x;
    
    x=n&MASK;
    for(;x>0;x>>=6)
        tmp+=x&1UL;
    n>>=1;
    
    x=n&MASK;
    for(;x>0;x>>=6)
        tmp+=((x&1UL)<<1);
    n>>=1;
    
    x=n&MASK;
    for(;x>0;x>>=6)
        tmp+=((x&1UL)<<2);
    n>>=1;
    
    x=n&MASK;
    for(;x>0;x>>=6)
        tmp+=((x&1UL)<<3);
    n>>=1;
    
    x=n&MASK;
    for(;x>0;x>>=6)
        tmp+=((x&1UL)*7);
    n>>=1;
    
    x=n&MASK;
    for(;x>0;x>>=6)
        tmp+=((x&1UL)*5);
    
    
    return mod9(tmp);
}
int main()
{
    for(uint32_t i=0;i<UINT32_MAX;i++){
        if(mod9(i)!=i%9)
            printf("Error %u %u\n",mod9(i),i%9);
        //if(i%10000==0)printf("ok %d\n",i);
    }
    printf("Suc");
    return 0;
}
