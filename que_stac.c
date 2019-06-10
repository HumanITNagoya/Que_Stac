#include <stdio.h>

/* データ格納場所の管理用変数 */
char que[5];   /* キュー */
char stac[5];  /* スタック */
int q_st = 0;
int q_end = 0;
int s_ct = 0;

/* 関数プロトタイプ */
void enq(char);
char deq();
void push(char);
char pop();

/* デバッグ用 */
void p_que();
void p_stac();
int i;

int main()
{
    char x;
    
    push('a');      p_stac();
    push('b');      p_stac();
    enq(pop());     p_stac(); p_que();
    enq('c');       p_que();
    push('d');      p_stac();
    push(deq());    p_que(); p_stac();
    x = pop();      p_stac();

    printf("xの値は%c\n" , x);

    return 0;
}

void enq(char n){
    que[q_st] = n;
    q_st++;
}

char deq(){
    char n = que[q_end];
    que[q_end] = '\0';
    q_end++;
    return n;
}

void push(char n){
    stac[s_ct] = n;
    s_ct++;
}

char pop(){
    s_ct--;
    char n = stac[s_ct];
    stac[s_ct] = '\0';
    return n;
}

void p_que(){
    printf("キューの中身 ");
    for(i=0;i<5;i++)
        printf("%c",que[i]);
    printf("\n");
}

void p_stac(){
    printf("スタックの中身 ");
    for(i=0;i<5;i++)
        printf("%c",stac[i]);
    printf("\n");
}
