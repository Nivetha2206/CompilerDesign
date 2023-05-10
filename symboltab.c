#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct symobol_Table{
    char v[20], t[10];
    int s;
}st[50];

char *tt[]={"short", "int", "float", "long", "double"};
int size[5]={1,2,4,6,8};
FILE *fp;

int main(){
    char s[100];
    int i=0,sp=0;

    fp=fopen("out.c","r");
    fscanf(fp,"%s",s);

    //print
    //print
    while(!feof(fp)){
        for (i=0;i<5;i++){
            if(strcmp(s,tt[i]==0)){
                fscanf(fp,"%s",s);
                printf(s,tt[i],size[i]);
                strcpy(st[sp].v,s);
                strcpy(st[sp].t,tt[i]);
                st[sp].s=size[i];
                sp++;
            }
        }
        fscanf(fp,"%s",s);
    }

}