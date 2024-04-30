#include <stdio.h>
#include <stdint.h>
#define MASK 0x11111111
uint32_t mod5(uint32_t n){
    
    if(n<5)
        return n;
    n-=5;
    uint32_t tmp=0,x;
    
    x=n&MASK;
    for(;x>0;x>>=4)
        tmp+=x&1UL;
    n>>=1;
    
    x=n&MASK;
    for(;x>0;x>>=4)
        tmp+=((x&1UL)<<1);
    n>>=1;
    
    x=n&MASK;
    for(;x>0;x>>=4)
        tmp+=((x&1UL)<<2);
    n>>=1;
    
    x=n&MASK;
    for(;x>0;x>>=4)
        tmp+=((x&1UL)*3);
    
    
    
    return mod5(tmp);
}
int main()
{
    
    printf("%u",mod5(UINT32_MAX-1));

    return 0;
}
