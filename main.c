#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int * create_contents(void){
    static int contents[9];
    for(int i=0;i<9;i++){
        contents[i]=i+1;
    }
    return contents;
}
void print_board(int row,int contents[9]){
    if(row==0){
        printf("*************\n");
    }
    printf("* ");
    for(int i=row;i<row+3;i++){
        if(contents[i]=='X'){
            printf("X * ");
        }else if(contents[i]=='O'){
            printf("O * ");
        }else{
            printf("  * ");
        }
    }
    printf("\n*************\n");
    if(row+3<7){
        print_board(row+3,contents);
    }
}
int check_for_victory(int c[9]){
    if((c[0]==c[1])&&(c[1]==c[2])){
        return 1;
    }else if((c[3]==c[4])&&(c[4]==c[5])){
        return 1;
    }else if((c[6]==c[7])&&(c[7]==c[8])){
        return 1;
    }else if((c[0]==c[3])&&(c[3]==c[6])){
        return 1;
    }else if((c[1]==c[4])&&(c[4]==c[7])){
        return 1;
    }else if((c[2]==c[5])&&(c[5]==c[8])){
        return 1;
    }else if((c[0]==c[4])&&(c[4]==c[8])){
        return 1;
    }else if((c[2]==c[4])&&(c[4]==c[6])){
        return 1;
    }
    return 0;
}
int is_board_full(int contents[9]){
    int counter=0;
    for(int i=0;i<9;i++){
        if((contents[i]=='X')||(contents[i]=='O')){
            counter+=1;
        }
    }
    if(counter==9){
        return 1;
    }
    return 0;
}
void players_move(char p1, int contents[9]){
    int choice = rand()%9;
    if((contents[choice]=='X')||(contents[choice]=='O')){
        players_move(p1, contents);
    }else{
        contents[choice]=p1;
    }
}
void play_game(char p1,char p2,int contents[9],clock_t start_time){
    for(int i=0;i<25;i++){printf("\n");}
    players_move(p1,contents);
    print_board(0,contents);
    if(check_for_victory(contents)==1){
        printf("%c's win!",p1);
    }else if(is_board_full(contents)==1){
        printf("Draw!");
    }else{
        start_time = clock();
        while (clock() < start_time + 1000);
        play_game(p2,p1,contents,start_time);
    }
}
int main(void){
    srand(time(NULL));
    int *p;
    clock_t start_time=clock();
    char choicep1='X';
    char choicep2='O';
    p=create_contents();
    for(int i=0;i<25;i++){printf("\n");}
    printf("T I C - T A C - T O E\n");
    print_board(0,p);
    while (clock() < start_time + 1000);
    play_game(choicep1,choicep2,p,start_time);
    return 0;
}
