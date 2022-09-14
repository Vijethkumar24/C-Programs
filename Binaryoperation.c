#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void calculate_the_maximum(int n, int k) {
    int And = 0, OR = 0, Xor = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(And < (i & j) && (i & j) < k)
                And = i & j;
            if(OR < (i | j) && (i | j) < k)
                OR = i | j;
            if(Xor < (i ^ j) && (i ^ j) < k)
                Xor = i ^ j;
        }
    }
    printf("%d\n", And);
    printf("%d\n", OR);
    printf("%d\n", Xor);
 
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
