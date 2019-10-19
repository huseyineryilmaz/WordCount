#include <stdio.h>

#define IN 1
#define OUT 0

int main(){
    int c, nl, nw, nc, state;

    FILE *file;
    file = fopen("test.txt", "r");  

    state = OUT;
    nl=nw=nc=0;
    if(file){
        while ((c=getc(file)) != EOF)
        {
            ++nc;
            if (c == '\n')
            {
                ++nl;
            }
            if (c == ' ' || c == '\n' || c == '\t')
            {
                state = OUT;
            }
            else if (state == OUT)
            {
                state = IN;
                ++nw;
            }
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
    fclose(file);
    return 0;

}