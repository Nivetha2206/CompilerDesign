#include <stdio.h>
#include <string.h>

int main(){
    char a[20];
    int i=0,j=0,id1=0,id2=0,id3=0;
    char identifier[10],op[10],constant[10];

    printf("Enter string: ");
    fgets(a,20,stdin);

    for (i=0;i<strlen(a);i++){

        //identifiers
        if(a[i]>='a' && a[i]<='z'){
            identifier[id1]=a[i];
            id1++;
            i++;
            while (a[i]>='a' && a[i]<='z' || a[i]>='0' && a[i]<='9'){
                identifier[id1]=a[i];
                id1++;
                i++;
            }
            identifier[id1]='\0';
            if (strcmp(identifier,"if")==0){
                printf("Keyword: ");
                for (j=0;j<id1;j++){
                    printf("%c",a[i]);
                }
            }
            else {
                printf("Identifier: ");
                for (j=0;j<id1;j++){
                    printf("%c",a[i]);
                }
            }
            printf("/n");
            id1=0;
        }

        // operators
        if (a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/' || a[i]=='%' || a[i]=='<' || a[i]=='>' || a[i]=='='){
            //op[id2]=a[i];
            //id2++;
            printf("%c", a[i]);
        }

        if (a[i]>='0' && a[i]<='9'){
            constant[id3]=a[i];
            id3++;
            i++;

            while (a[i]>='0' && a[i]<='9')
            {
                constant[id3]=a[i];
                id3++;
                i++;
            }
            printf("Constant: ");
            for (j=0;j<id3;j++){
                printf("%c",a[i]);
            }
            id3=0;
            
        }
    }
}