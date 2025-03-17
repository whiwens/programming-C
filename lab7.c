
#include <stdio.h>
#include <string.h>

struct humen{
    char name[100], sname[100], pol[10];
    int byear, height;
};

int main(){
    int N = 4;
    struct humen a[N], b[N], t;
    char name[100], sname[100], pol[10];
    int byear, height;
    for(int i = 0; i<N; i++){
        printf("введите имя %d-го человека: ", i+1);
        scanf("%s", name);
        printf("введите фамилию %d-го человека: ", i+1);
        scanf("%s", sname);
        printf("введите год рождения %d-го человека: ", i+1);
        scanf("%d", &byear);
        printf("введите пол %d-го человека: ", i+1);
        scanf("%s", pol);
        printf("введите рост %d-го человека: ", i+1);
        scanf("%d", &height);
        strcpy(a[i].name, name);
        strcpy(a[i].sname, sname);
        strcpy(a[i].pol, pol);
        a[i].byear = byear;
        a[i].height = height;
    }
    
    for(int i = 0; i<N; i++) b[i] = a[i];
    for(int i = 0; i<N-1; i++){
        for(int j = 0; j<N-i-1; j++){
            if(b[j].byear < b[j+1].byear){
                t = b[j+1];
                b[j+1] = b[j];
                b[j] = t;
            }
        }
    }
    for(int i = 0; i<N; i++){
        printf("%d %s %s %s %d %d\n", i, b[i].name, b[i].sname, b[i].pol, b[i].byear, b[i].height);
    }
    return 0;
}
